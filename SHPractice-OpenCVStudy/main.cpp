//
//  main.cpp
//  SHPractice-OpenCVStudy
//
//  Created by Shine on 09/05/2018.
//  Copyright © 2018 shine. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Mat image = imread("/Users/shine/Downloads/opencv-3.4.1/samples/data/apple.jpg");
//    namedWindow("testOpenCV",WINDOW_AUTOSIZE);
//    imshow("testOpenCV", image);
//    imwrite("/Users/shine/Desktop/test.jpg", image);   //输出图像到文件
//    waitKey(2000);   //显示2秒钟
    
    
    //再来一个图片叠加的例子
    Mat imageDst = imread("/Users/shine/Downloads/iOSAppTemplate-master/iOSAppTemplate/Resource/images/7.jpg");
    Mat imageROI = image(Rect(0,0,imageDst.cols,imageDst.rows));  //原始图片
    
    //先显示叠加的小图
//    namedWindow("小logo");
//    imshow("小logo", imageDst);
//    waitKey();
    
    addWeighted(imageROI, 0.5, imageDst, 0.3, 0., imageROI); //如果相叠加的两个Mat尺寸不相同会报异常:libc++abi.dylib: terminating with uncaught exception of type cv::Exception: OpenCV(3.4.1) /Users/shine/Downloads/opencv-3.4.1/modules/core/src/arithm.cpp:659: error: (-209) The operation is neither 'array op array' (where arrays have the same size and the same number of channels), nor 'array op scalar', nor 'scalar op array' in function arithm_op
    
    namedWindow("叠加事例",WINDOW_AUTOSIZE);
    imshow("叠加事例", image);   //这里imshow第二个参数一定要是image,不是imageROI,imageROI和imageDst尺寸一样大，会看到叠加的图大小一样.
    waitKey();
    
                         
    return 0;
}



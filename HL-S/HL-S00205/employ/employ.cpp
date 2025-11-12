#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int r;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    // 这东西纯看脸……
    srand(time(0));
    r = rand()*rand()%998244353+1;
    printf("%d\n",r);
    /*
    我不习惯没有带着你的打火机（不对呀，我为什么要带打火机）
    这里是普通中学的化学实验室^_^
    灰蒙蒙的天气……（忘词了……）
    啊啊啊！！！啊啊啊！！！啊啊啊！！！啊啊啊！！！
    啊啊啊！！！啊啊啊！！！啊啊啊！！！啊啊啊！！！
    啊啊啊！！！啊啊啊！！！啊啊啊！！！啊啊啊！！！
    啊啊啊！！！啊啊啊！！！啊啊啊！！！啊啊啊！！！
    */

    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 要bomb了，我要上迷惑行为大赏！
// 18:17:12 再次检查所有的文件的输入输出（即使是随机数……）
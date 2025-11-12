// 咦？这年头NOI的测评机都是Intel Ultra9 285K了
// Wow！96GB的内存？！这样算来……我的电脑只是它的1/3？
#include<stdio.h>
int t,n,a[100010][4],p[4],mx;
void dfs(int x)
{
    if(x > n)
    {
        mx = (p[0] > mx)?p[0]:mx;
        return;
    }
    for(int i = 1;i<=3;++i)
    {
        if(a[x][0])
        {
//            printf("No. %d,to %d,failed visited\n",x,i);
            continue;
        }
        if(p[i]+1 > (n/2))
        {
//            printf("No. %d,to %d,failed fly\n",x,i);
            continue;
        }

        a[x][0] = i;
        ++p[i];
        p[0] += a[x][i];
//        printf("No. %d,to %d,num %d\n",x,i,p[i]);

        dfs(x+1);

        a[x][0] = 0;
        --p[i];
        p[0] -= a[x][i];
//        printf("No. %d,out %d,num %d\n",x,i,p[i]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    /*
    再努力努力，至少这个可以看懂题……
    思路就是纯暴力（ps：虽然不是正解）
    啊！！！dfs怎么写！！
    咦？为什么题面的共“13”页可以点呀？
    但是这个功能好鸡肋，还不如让前面的第几页可以点好用呢……
    啊啊啊！！！这对吗？我要刷新纪录了（有一次是70分）
    完了，要挂0了……
    呀哈！写出来了……一点……我能蒙上也是奇迹了！
    《奇迹再现》：你相信光吗？
    呀，不会改了……
    我勒个去！我见到曙光了！！！
    我去，我太天才了！！！（虽然超时，但有答案！！！）
    啊啊啊啊！！！我太天才了！！！！
    我先存个副本，我看看能不能加速！！！
    我哩个，一看其实就能过两个测试点？？？行吧10分我接受了
    A：真受不了
    B：那就胖着
    （好像军训纪实……）
    算了整不出来了，重新蒙蒙下一道题    ——18:11:22
    我哩个，差点忘记把文件输入输出放回来……    ——18:15:28
    */
    scanf("%d",&t);
    for(int i = 1;i<=t;++i)
    {
        scanf("%d",&n);
        p[0]=p[1]=p[2]=p[3]=mx=0;
        for(int j = 1;j<=n;++j)
        {
            scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
            a[j][0] = 0;
        }
        dfs(1);
        printf("%d\n",mx);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 我要上迷惑行为大赏！
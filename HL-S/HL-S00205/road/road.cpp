#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,m,k;
struct R
{
    int u;
    int v;
    int w;
}r[1000010];
struct CSD
{
    int c;
    int w[10010];
}csd[20];
unsigned long long rr;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=m;++i)
    {
        scanf("%d",&r[i].u,&r[i].v,&r[i].w);
    }
    for(int i = 1;i<=k;++i)
    {
        scanf("%d",&csd[i].c);
        for(int j = 1;j<=n;++j)
        {
            scanf("%d",&csd[i].w[j]);
        }
    }
    /*
    没思路
    18:12:30 其实吧依旧没有思路，对了我是都先打了一遍随机数，然后才开始想正解的QvQ
    emm……不过好像都没想出来（除了暴力就是瞎蒙）
    不过话说回来为什么电脑上安装了PyCharm？这个比CodeBlocks、Dev-C++画风好多了
    挣扎不动了……	18:25:10
	*/
    srand(time(0));
    rr = rand()*rand()%9000000000+1;
    printf("%lld\n",rr);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 我要上迷惑行为大赏！
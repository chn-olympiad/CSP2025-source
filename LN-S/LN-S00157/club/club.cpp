#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][10],n,b[N][10],c[10];
struct node
{
    int num,f;
}d[N];
bool cmp(node x,node y)
{
    return x.f>y.f;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int p=1;
        c[1]=c[2]=c[3]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=a[i][j];
            }
            sort(b[i]+1,b[i]+4);
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]==b[i][3])
                {
                    c[j]++;
                }
            }
        }
        for(int i=1;i<=3;i++)
        {
            if(c[i]>c[p])
                p=i;
        }
        int ans=0;
        bool flag=0;
        int t=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][p]==b[j][3])
            {
                t++;
                d[t].num=j;
                d[t].f=b[j][3]-b[j][2];
            }
            else
            {
                ans+=b[j][3];
            }
        }
        sort(d+1,d+t+1,cmp);
        for(int j=1;j<=t;j++)
        {
            int jj=d[j].num;
            if(j<=n/2) ans+=b[jj][3];
            else ans+=b[jj][2];
        }
        printf("%d\n",ans);
    }
    return 0;
}

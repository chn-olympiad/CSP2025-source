#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int t;
int n,a[5],m[N][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int ans=0,cnt[5]={0};
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int maxn1=0,maxp1=0,maxn2=0,maxp2=0;
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[j]);
                if(a[j]>maxn1)
                {
                    maxn2=maxn1;
                    maxp2=maxp1;
                    maxn1=a[j];
                    maxp1=j;
                }
                else if(a[j]>maxn2)
                {
                    maxn2=a[j];
                    maxp2=j;
                }
            }
            m[i][0]=maxn1-maxn2;
            m[i][1]=maxp1;
            ans+=maxn1;
            cnt[maxp1]++;
        }
        for(int k=1;k<=3;k++)
        {
            if(cnt[k]>n/2)
            {
                int cnt_x=cnt[k]-n/2;
                while(cnt_x--)
                {
                    int minn=inf,minm=0;
                    for(int i=1;i<=n;i++)
                    {
                        if(m[i][0]<minn&&m[i][1]==k)
                        {
                            minn=m[i][0];
                            minm=i;
                        }
                    }
                    ans-=minn;
                    m[minm][0]=inf;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

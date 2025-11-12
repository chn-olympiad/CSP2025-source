#include<bits/stdc++.h>
using namespace std;
int n;
struct p{
    int x[4];
    int m1,m2,deta;
}a[100005];
bool cmp(p xa,p ya)
{
    int xm=xa.x[xa.m1],ym=ya.x[ya.m1];
    if(xm>=ym)return 1;
    return 0;
}
long long ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            ans=0;
            for(int j=1;j<=3;j++)scanf("%d",&a[i].x[j]);
            int maxn=max(max(a[i].x[1],a[i].x[2]),a[i].x[3]);
            a[i].m1=maxn;
            if(maxn==a[i].x[1])
            {
                a[i].m2=max(a[i].x[2],a[i].x[3]);
                a[i].deta=a[i].m1-a[i].m2;
                a[i].m1=1;
                if(a[i].m2==a[i].x[2])a[i].m2=2;
                else a[i].m2=3;
            }
            else if(maxn==a[i].x[2])
            {
                a[i].m2=max(a[i].x[1],a[i].x[3]);
                a[i].deta=a[i].m1-a[i].m2;
                a[i].m1=2;
                if(a[i].m2==a[i].x[1])a[i].m2=1;
                else a[i].m2=3;
            }
            else
            {
                a[i].m2=max(a[i].x[2],a[i].x[1]);
                a[i].deta=a[i].m1-a[i].m2;
                a[i].m1=3;
                if(a[i].m2==a[i].x[2])a[i].m2=2;
                else a[i].m2=1;
            }

        }
        int v=(n>>1);
        sort(a+1,a+1+n,cmp);

        //for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d\n",a[i].x[1],a[i].x[2],a[i].x[3],a[i].x[a[i].m1],a[i].x[a[i].m2],a[i].deta);

        int v1[4]={0},deta1[4][100005]={0},cnt[4]={0};
        for(int i=1;i<=n;i++)
        {
            int maxn=a[i].x[a[i].m1];
            if(v1[a[i].m1]<v)
            {
                ans+=maxn;
                v1[a[i].m1]++;
                cnt[a[i].m1]++;
                deta1[a[i].m1][cnt[a[i].m1]]=a[i].deta;
            }
            else
            {
                int min_deta=0x3f3f3f3f,tmp=0;
                for(int j=1;j<=cnt[a[i].m1];j++)
                {
                    if(min_deta>deta1[a[i].m1][j])
                    {
                        min_deta=deta1[a[i].m1][j];
                        tmp=j;
                    }
                }
                if(a[i].deta>min_deta)
                {
                    ans-=deta1[a[i].m1][tmp];
                    ans+=a[i].x[a[i].m1];
                    deta1[a[i].m1][tmp]=a[i].deta;
                }
                else ans+=a[i].x[a[i].m2];
            }
        }
        printf("%d\n",ans);
    }
}

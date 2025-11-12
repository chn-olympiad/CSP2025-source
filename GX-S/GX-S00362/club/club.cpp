#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#define int long long
using namespace std;
int n;
int T;
int a[100010],b[100010],c[100010];
int vis1[100010],vis2[100010],vis3[100010];
int vis[1000010];
bool gz1(int x,int y)
{
    return x>y;
} 
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for (int ii=1;ii<=T;ii++)
    {
        scanf("%lld",&n);
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(vis3,0,sizeof(vis3));
        int cnt=0;
        int ans=0,flag1=0,flag2=0,flag3=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            int maxx=max(a[i],max(b[i],c[i]));
            ans+=maxx;
            if (a[i]==maxx) flag1++,vis1[i]++;
            else if (b[i]==maxx) flag2++,vis2[i]++;
            else if (c[i]==maxx) flag3++,vis3[i]++; 
        }
        int maxx=max(flag1,max(flag2,flag3));
        if (maxx<n/2) cout<<ans<<endl;
        else
        {
            if (flag1==maxx)
            {
                for (int i=1;i<=n;i++)
                    if (vis1[i]==1)
                       vis[++cnt]=max(b[i]-a[i],c[i]-a[i]);
                sort(vis+1,vis+1+cnt,gz1);
                for (int i=1;i<=maxx-n/2;i++)
                  ans+=vis[i];  
            }
            else if (flag2==maxx)
            {
                for (int i=1;i<=n;i++)
                    if (vis2[i]==1)
                       vis[++cnt]=max(c[i]-b[i],a[i]-b[i]);
                sort(vis+1,vis+1+cnt,gz1);
                for (int i=1;i<=maxx-n/2;i++)
                  ans+=vis[i]; 
            }
            else 
            {
                for (int i=1;i<=n;i++)
                    if (vis3[i]==1)
                       vis[++cnt]=max(b[i]-c[i],a[i]-c[i]);
                sort(vis+1,vis+1+cnt,gz1);
                for (int i=1;i<=maxx-n/2;i++)
                  ans+=vis[i]; 
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}


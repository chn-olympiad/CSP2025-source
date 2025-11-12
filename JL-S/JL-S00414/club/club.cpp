#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,ans;
const ll N=1e5+10;
ll s[N][5];
ll cnt[5];
bool vis[N];
namespace sub1
{
    void sf()
    {
        ll sum=0;
        for(int i=1;i<=n/2;i++)
            sum+=s[i][1];
        for(int i=(n/2)+1;i<=n;i++)
            sum+=s[i][2];
        cout<<sum<<'\n';
        return;
    }
}
namespace sub2
{
    void sf()
    {
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=s[i][1];
        }
        cout<<sum;
        return;
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        bool f1=1,f2=1;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i][1]>>s[i][2]>>s[i][3];
            if(s[i][2])
                f1=0;
            else if(s[i][3])
                f2=0;
            s[i][4]=max(s[i][1],max(s[i][2],s[i][3]));
            vis[i]=0;
        }
        if(f1)
        {
            sub1::sf();
            continue;
        }
        if(f2&&f1)
        {
            sub2::sf();
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(s[i][j]==s[i][4]&&cnt[j]<=n/2)
                {
                    cnt[j]++;
                    ans+=s[i][j];
                    vis[i]=1;
                }

            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3&&cnt[j]<=n/2;j++)
                if(!vis[i])
                    ans+=s[i][j],vis[i]=1,cnt[j]++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

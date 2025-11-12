#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    const char endl='\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    //------------
    ll ans=0,qwe=0,wer=0;
    ll n,k;
    ll s[500005];
    //ll dp[][500005];
    int vis[500005]={0};
    cin>>n>>k;
    for (int p=1;p<=n;p++)
    {
        cin>>s[p];
        if(s[p]==1)
        {
            qwe++;
        }
        if(s[p]!=1&&s[p]!=0)
        {
            wer=1;
        }
    }
    if(wer==0)
    {
        cout<<qwe;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n-i+1;j++)
        {
            ll sum=s[j];
            bool is_=true;
            for (int u=1;u<i;u++)
            {
                if(vis[j+u]==1)
                {
                    is_=false;
                    break;
                }
                sum^=s[j+u];
            }
            if(is_==false)
            {
                continue;
            }
            if(sum==k)
            {
                ans++;
                for (int u=0;u<i;u++)
                {
                    vis[j+u]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

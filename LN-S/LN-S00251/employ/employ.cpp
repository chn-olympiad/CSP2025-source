#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],rgo[505],ans=1;
bool sht[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        sht[i]=x-'0';
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    if(n==m)
    {
        for(int i=1;i<=n;i++)
        {
            if(sht[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }
        cout<<ans;
        return 0;
    }
    int ou=0,now=1;
    while(c[now]<=ou)
    {
        cout<<c[now]<<' '<<ou<<endl;
        ou++;
        now++;
    }
    n-=ou;
    cout<<n<<' '<<ou<<endl;
    if(n<m)
    {
        cout<<0;
        //return 0;
    }
    for(int i=1;i<=n+ou;i++)
    {
        ans=(ans*i)%mod;
    }
    cout<<ans;
    return 0;
}

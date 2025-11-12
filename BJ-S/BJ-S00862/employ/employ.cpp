#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N1=998244353;
char a[510];
int b[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(a[1]=='1')
    {
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            cout<<ans<<"\n";
            if(ans%N1!=0) ans%=N1;
        }
        cout<<ans;
    }
    return 0;
}

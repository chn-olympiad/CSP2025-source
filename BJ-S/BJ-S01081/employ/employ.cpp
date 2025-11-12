#include<iostream>
#include<string>
using namespace std;
const int MOD=998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    long long ans=1;
    for(int i=1;i<=n;++i)
    {
        ans*=i;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}

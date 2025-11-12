#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
string t;
int n,a;
int m;
int cnt=1;
long long num=1;
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
    }
    for(int j=n;j>=1;j--)
    {
        num = (num*j)%998244353;
        //cout<<num<<" "<<j<<endl;
    }
        ans = (ans+num)%998244353;
    cout<<ans;
    return 0;
}

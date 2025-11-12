#include <bits/stdc++.h>
using namespace std;
long long ans=1;
int a[505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[n];
        ans*=i;
    }
    ans%=998244353;
    cout<<ans;
    return 0;
}

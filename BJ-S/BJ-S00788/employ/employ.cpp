#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
string s;
long long a[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
    }
    for (long long i=n;i>=1;i--){
        ans=ans*i%998244353;
    }
    cout << ans;
    return 0;
}

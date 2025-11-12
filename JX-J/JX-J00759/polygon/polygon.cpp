#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
long long a[50002];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    long long n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=i;
    }
    cout << sum % mod;
    return 0;
}

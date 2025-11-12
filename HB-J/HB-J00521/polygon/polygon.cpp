#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
int n;
int a[5010];
int s[5010];
ll cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int l=1;l<n-1;l++) for(int r=l+2;r<=n;r++) if(s[r]-s[l-1]>a[r]*2) cnt++;
    cout << cnt%MOD;
    return 0;
}

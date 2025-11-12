#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5005],maxn[5005],cnt[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++) cin>>a[i];
    if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

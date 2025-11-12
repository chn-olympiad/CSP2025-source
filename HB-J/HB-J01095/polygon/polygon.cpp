#include <bits/stdc++.h>
using namespace std;
const int SIZE=5000;
//define int long long
int n,a[SIZE+1],/*_a[SIZE+1],*/ans,Size,cnt,stick[SIZE+1];
void solve(int i){
    if(a[i]+a[i+1]>a[i+2]) ans++;
}
/*
if(jud()) ans++;
if(ans>998244353) ans=1;
*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    //for(i=1;i<=n;i++) _a[i]=_a[i-1]+a[i];
    for(i=0;i<=n-2) solve();
    cout<<ans<<endl;
    return 0;
}

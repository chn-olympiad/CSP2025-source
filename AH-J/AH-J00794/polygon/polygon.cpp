#include<bits/stdc++.h>
using namespace std;
const int N=5010,MOD=998244353;
int a[N];
long long ans,x=1,y=1;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
if(a[n]==1){
    for(int i=3;i<=n;i++){
        x=1;y=1;
        for(int j=n;j>=i+1;j--){
            x*=j%MOD;
        }
        for(int j=n-i;j>=1;j--){
            y*=j%MOD;
        }
        ans=(ans+x/y)%MOD;
    }
    cout<<ans;
    return 0;
}
if(n==3){
    if(a[1]+a[2]>a[3]){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
 return 0;
}

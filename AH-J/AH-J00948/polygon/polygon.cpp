#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],t[5005],cnt=1,s=1,ans;
signed main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==1) ans++;
}
if(ans==n){
    for(int i=1;i<n;i++){
    s*=i;
    if(i>=3){
        int x=1;
        for(int j=n-i+1;j<=n;j++){
            x*=j;
        }
        cnt+=x/s;
    }
  }
}else if(n<3){
cnt=0;
}else if(n==3){
int mx=0,sum=0;
for(int i=1;i<=n;i++){
    mx=max(mx,a[i]);
    sum+=a[i];
}
if(sum>mx*2) cnt++;
}
cout<<cnt%998%244%353;
return 0;
}

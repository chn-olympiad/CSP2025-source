#include <bits/stdc++.h>
using namespace std;
int n,cha,cnt,ans=0,maxl,t;
int a[5050],b[5000];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cnt=1;
for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++){
        b[cnt]=a[i]-a[j];
        cnt++;
    }
}
ans=0;
for(int i=3;i<n;i++){
    cha=0;
    maxl=a[n]*2;
    for(int j=n;j>=n-i+1;j--){
        cha=cha+a[j];
    }
    if(cha>maxl)
    ans+=cha-maxl+1;
}
cha=0;
for(int i=1;i<=n;i++){
    cha=cha+a[i];
}
if(cha>maxl)
    ans++;
    cout<<ans;
return 0;
}

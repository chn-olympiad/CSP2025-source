#include<bits/stdc++.h>

using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;cin>>n;
int a[n+1],he=0,maxn=-1;
for(int i=1;i<=n;i++){
    cin>>a[i];he+=a[i];
    if(maxn<a[i]) maxn=a[i];
}
if(n<3){
    cout<<0;return 0;
}
if(n==3 && maxn*2<he) cout<<1;
else cout<<0;




return 0;
}

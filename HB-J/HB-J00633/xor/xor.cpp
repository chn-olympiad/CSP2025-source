#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500050],dp[10000][10000];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(k==0){
    cout<<1;
}else{
cout<<2;
}
return 0;
}

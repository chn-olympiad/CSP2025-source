#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],xum[500001],cnt,l=1,r=1;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++) cin>>a[i],xum[i]=(xum[i-1]^a[i]);
while(r<=n){
if((xum[r]^xum[l-1])==k)  cnt++,l=r+1,r=r+1;
r++;
}
cout<<cnt;
return 0;
}

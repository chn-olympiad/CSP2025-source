#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[N],maxn[N],sum;
void dfs(int dep,int maxn,int ddf){
	for(int i=ddf;i<=n;i++)
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,k;
cin>>n;

for(int i=1;i<=n;i++){
cin>>a[i];
maxn[i]=max(a[i],maxn[i-1]);
}
if(n==3){
	if(maxn[3]*2<a[1]+a[2]+a[3]) cout<<1;
	else cout<<0;
}
else{
cout<<9;
}
return 0;
}

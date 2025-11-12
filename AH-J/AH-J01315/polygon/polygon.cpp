#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[10010];
bool c;
void dfs(long long x,long long shu,long long he,long long maxn){
	if(x==n){
		if(shu>=3&&he>maxn*2)ans++;
		return;
	}
	if(n-x<3-shu)return;
	dfs(x+1,shu+1,he+a[x],max(maxn,a[x]));
	dfs(x+1,shu,he,maxn);
	return ;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]!=1)c=1;
}
if(c){
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
if(!c){
	ans=0;
	for(int i=3;i<=n;i++){
		long long f=1,g=1;
		for(int j=n,l=i;l>0;l--,j--){
			f=f*j%998244353;
			g=g*l%998244353;
		}
		ans=(ans+f/g)%998244353;
	}
	cout<<ans;
	return 0;
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,a[5006];
long long ans,cj[5006];
void dfs(int xs,int x,int mx,int h){
	if(x==n+1){
		ans+=(xs>=3&&h>mx*2);
		return;
	}
	dfs(xs,x+1,mx,h);
	dfs(xs+1,x+1,max(mx,a[x]),h+a[x]);
}
long long ksm(long long x,long long y){
	long long d=1;
	while(y){
		if(y&1) d=d*x%md;
		x*=x,x%=md,y>>=1;
	}
	return d;
}
long long ny(long long x,long long y){
	return x*ksm(y,md-2)%md;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cj[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i],cj[i]=i*cj[i-1],cj[i]%=md;
	if(n<=20) dfs(0,1,0,0),cout<<ans;
	else{
		for(int i=3;i<=n;i++) ans+=ny(cj[n],cj[i]*cj[n-i]%md),ans%=md;
		cout<<ans; 
	}
	return 0;
}
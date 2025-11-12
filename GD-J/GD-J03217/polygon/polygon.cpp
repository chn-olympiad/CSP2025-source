//gitxiaozheng
//rp++!
#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
int a[maxn],b[maxn],c[maxn],tans=0;
bool chos[maxn];
int n;
void dfs(int zs,int st,int lsti,int sum111){
	if(zs==st){
		if(c[lsti]*2<sum111){
			tans++;	
		}
		return;
	}
	for(int i=lsti;i<=n;i++){
		if(!chos[i]){
			chos[i]=true;
			dfs(zs,st+1,i,sum111+a[i]);
			chos[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=max(c[i-1],a[i]);
		b[i]=(b[i-1]+a[i])%mod;
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if( n==3){
		if(a[1]+a[2]+a[3]>c[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		tans=0;
		dfs(i,0,0,0);
		ans=(ans+tans)%mod;
	}
	cout<<(ans+1)/2;
	return 0;
}

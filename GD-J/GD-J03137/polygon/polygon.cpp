#include<iostream>
using namespace std;
int n,a[100001],p[100001],ans=0,minn[100001];
int mod=998244353;
void dfs(int k,int len,int sum,int maxn){
	if(len+n-k+1<3) return;
	if(k==n+1){
		if(sum>maxn*2) ans++,ans%=mod;
		return;
	}
	p[k]=0;
	dfs(k+1,len,sum,maxn);
	p[k]=1;
	dfs(k+1,len+1,sum+a[k],max(maxn,a[k]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	minn[n+1]=1e9;
	for(int i=n;i>=1;i--) minn[i]=min(minn[i+1],a[i]);
	dfs(1,0,0,-1);
	cout<<ans<<"\n";
	return 0;    
}

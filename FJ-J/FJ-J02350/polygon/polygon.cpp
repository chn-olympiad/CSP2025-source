#include <bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e4+100;
int const mod=998244353;
int n,a[N],mi=INT_MAX,sum=0,ans;
bool vis[N];
int dfs(int last,int st,int m){
	if(st>m){
		if(last!=0) return 0;
//		for(int i=1;i<=n;i++){
//			if(vis[i]) cout<<a[i]<<' ';
//		}
//		cout<<endl;
		return 1;
	}
	if((last==0&&st>=3)){
//		for(int i=1;i<=n;i++){
//			if(vis[i]) cout<<a[i]<<' ';
//		}
//		cout<<endl;
		return 1;
	}
	int sum=0;
	if(!vis[st]){
		vis[st]=1;
		sum+=dfs(last-a[st],st+1,m)%mod;
		vis[st]=0;
		sum+=dfs(last,st+1,m)%mod;
	}
	return sum%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);
	mi=a[1]+a[2]+a[3];
//	dfs(10,1,5);
//	return 1;
	for(int i=mi;i<=sum;i++){
		int m=lower_bound(a+1,a+1+n,i/2)-a;
		if(m>n) m=n;
//		cout<<m<<' '<<i<<endl;
		if(a[m]*2>=i) m--;
		if(m<3) continue;
		//from 1 to m to i
		memset(vis,0,sizeof(vis));
		ans=(ans+dfs(i,1,m))%mod;
	}
	cout<<ans;
	return 0;
}

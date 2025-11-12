#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005,M=1e6+5;
int n,sum[N][N],maxi=-1e9;
int a[M],b[M],c[M];
bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]!=0||c[i]!=0){
			return false;
		}
	}
	return true;
}
void dfs(int cur,int cnta,int cntb,int cntc,int cnt,int ans){
	if(cnt==n||cur>n){
		maxi=max(maxi,ans);
		return ;
	}
	if(cnta<(n/2)){
		dfs(cur+1,cnta+1,cntb,cntc,cnt+1,ans+sum[cur][1]);
	}
	if(cntb<(n/2)){
		dfs(cur+1,cnta,cntb+1,cntc,cnt+1,ans+sum[cur][2]);
	}
	if(cntc<(n/2)){
		dfs(cur+1,cnta,cntb,cntc+1,cnt+1,ans+sum[cur][3]);
	}
	return ;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>sum[i][j];
		}
		a[i]=sum[i][1];
		b[i]=sum[i][2];
		c[i]=sum[i][3];
	}
	if(check()==true){
		int ans=0;
		sort(a+1,a+1+n);
		for(int i=n;i>=n/2;i--){
			ans+=a[i];
		}
	}
	maxi=-1e9;
	dfs(1,0,0,0,0,0);
	cout<<maxi<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

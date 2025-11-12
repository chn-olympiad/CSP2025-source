#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=5005;
int ans,n,a[N],s[N][N];
void dfs(int idx,int maxn,int sum,int cnt){
	if(idx>n){
		if(cnt>=3&&sum>2*maxn) ans=(ans+1)%mod;
		return ;
	}
	dfs(idx+1,maxn,sum,cnt);
	dfs(idx+1,max(maxn,a[idx]),sum+a[idx],cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		int ans=0;
		s[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i){
					s[i][j]=1;
					continue;
				}
				s[i][j]=(s[i-1][j-1]+s[i-1][j])%mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+s[n][i])%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;         
}

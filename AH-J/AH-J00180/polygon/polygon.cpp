#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,maxx,c[5005][5005];
const int mod=998244353;
void dfs(int i,int s,int cnt){
	if(cnt>=2){
		int k=lower_bound(a+1,a+n+1,s)-a-1;
		ans+=max(0,k-i+1);
		ans%=mod;
	}
	for(int j=i;j<=n;j++){
		dfs(j+1,s+a[j],cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx<=1){
		c[1][1]=c[1][0]=1;
		for(int i=2;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				c[i][j]%=mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		}
	}
	else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],p[4];
long long ans;
bool vis[100005][4];
void dfs(int dep,long long sum){
	for(int i=1;i<=3;i++){
		if(p[i]>n/2)return;
	}
	if(dep>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(!vis[dep][i]){
			p[i]++;
			sum+=a[dep][i];
			vis[dep][i]=true;
			dfs(dep+1,sum);
			vis[dep][i]=false;
			sum-=a[dep][i];
			p[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=3;i++){
			p[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

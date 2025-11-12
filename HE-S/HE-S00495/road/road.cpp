#include<bits/stdc++.h>
using namespace std;
int n,m,k,tr[10010][10010],dp[10010][10010],t[10010],sum=0,ans=0x3f3f3f;
bool f=0;
void dfs(int x){
	t[x]=1;
	for(int i=1;i<=n,t[i]==0;i++){
		t[i]=1;
		sum+=tr[x][i];
		for(int j=2;j<=n;j++){
			if(t[j]==0){
				f=1;
				break;
			}
		}
		if(f==1){
			f=0;
			dfs(i);
		}
		else{
			ans=min(ans,sum);
			return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(tr,0x3f3f3f,sizeof(tr));
	memset(dp,0x3f3f3f,sizeof(dp));
	memset(t,0,sizeof(t));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		tr[a][b]=c;
	}
	for(int i=1;i<=k;i++){
		int d[10010];
		cin>>d[0];
		for(int j=1;j<=n;j++) cin>>d[j];
		for(int j=2;j<=n;j++){
			for(int l=1;l<j;l++){
				int cost=d[0]+d[j]+d[l];
				tr[l][j]=min(tr[l][j],cost);
			}
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=1;j<i;j++){
			tr[i][j]=min(tr[i][j],tr[j][i]);
			tr[j][i]=tr[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
} 

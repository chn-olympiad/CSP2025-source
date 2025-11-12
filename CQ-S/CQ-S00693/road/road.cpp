#include<bits/stdc++.h>
using namespace std;
struct ap{
	int a,b,c;
}arr[1000005];
int n,m,k,p[15],dp[10005][10005],f[10005],ans,brr[15][10005],ag;
bool cmp(ap x,ap y){
	return x.c<y.c;
}
int find(int x){
	while(f[x]!=x) f[x]=f[f[x]],x=f[x];
	return x;
}
void memery(int x,int y){
	f[find(x)]=find(y);
}
struct node{
	int to,p; 
};
vector<node> vt[10005];
void dfs(int x,int f,int sum){
	for(int i=0;i<vt[x].size();i++){
		if(vt[x][i].to==f) continue;
		dp[ag][vt[x][i].to]=dp[vt[x][i].to][ag]=max(dp[ag][vt[x][i].to],max(sum,vt[x][i].p));
		dfs(vt[x][i].to,x,dp[ag][vt[x][i].to]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>arr[i].a>>arr[i].b>>arr[i].c;
	sort(arr+1,arr+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			brr[i][j]=x;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		if(find(arr[i].a)!=find(arr[i].b)){
			memery(arr[i].a,arr[i].b);
			ans+=arr[i].c;
			vt[arr[i].a].push_back({arr[i].b,arr[i].c}); 
			vt[arr[i].b].push_back({arr[i].a,arr[i].c}); 
		}
	}
	for(int i=1;i<=n;i++) ag=i,dfs(i,0,0);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				int need=p[i]+brr[i][j]+brr[i][l],sub=dp[j][l];
				if(sub>need) ans-=sub,ans+=need;
			}
		}
	}
	cout<<ans;
	return 0;
} 

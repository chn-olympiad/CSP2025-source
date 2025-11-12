#include<bits/stdc++.h>
using namespace std;
const int N=2e4,M=1e6+5;
int n,m,k,u[M],v1[M],w[M],c[15],a[15][N],q3[N];
long long mi=1e18,ans;
map<int,long long>q1[N],q2;
vector<int>v[N];
void dfs(int x,int cnt){
	if(cnt==n){
		mi=min(mi,ans);
		return;
	}
	for(auto xx:v[x]){
		if(q2[xx])continue;
		q2[xx]=1;
		ans+=q1[xx][x];
		if(xx<=n){
			dfs(xx,cnt+1);
		}else{
			ans+=q3[xx];
			dfs(xx,cnt);
			ans-=q3[xx];
		}
		q2[xx]=0;
		ans-=q1[xx][x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v1[i]>>w[i];
		v[u[i]].push_back(v1[i]);
		v[v1[i]].push_back(u[i]);
		q1[u[i]][v1[i]]=w[i];
		q1[v1[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		q3[m+i]=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			v[m+i].push_back(j);
			v[j].push_back(m+i);
			q1[m+i][j]=a[i][j];
			q1[j][m+i]=a[i][j];
		}
	}
	q2[1]=1;
	dfs(1,1);
	cout<<mi;
	return 0;
 } 

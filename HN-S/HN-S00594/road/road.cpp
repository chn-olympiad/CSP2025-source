#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to;
	int next;
	long long value;
	bool fla;
}edges[2000001];
int head[10001],f=0,n,m;
bool flag[10001];
long long ans[10002],b[11][10001],c[11];
void bian(int u,int v,long long w){
	edges[f].to=v;
	edges[f].next=head[u];
	head[u]=f;
	edges[f].value=w;
	f++;
}
int cmp(edge a,edge b){
	if(a.value<b.value){
		return a.value<b.value;
	}
}
void shuang(int u,int v,long long w){
	bian(u,v,w);
	bian(v,u,w);
}
void dfs(int u,int f,int sum){
	bool fl=0;
	for(int i=head[u];i!=-1;i=edges[i].next){
		if(edges[i].to!=f&&flag[edges[i].to]==0&&edges[i].to>0&&edges[i].fla==1){
			fl=1;
			flag[edges[i].to]=1;
			dfs(edges[i].to,u,sum+1);
		}
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k,u,v,F=0;
	long long w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=m;i++){
		edges[i].fla=0;
	}
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		shuang(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			shuang(-i,j,b[i][j]);
		}
	}
	ans[0]=0;
	flag[1]=1;
	sort(edges+1,edges+2*m+1,cmp);
	for(int i=1;i<n;i++){
		ans[0]=ans[0]+edges[i].value;
		edges[i].fla=1;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			F=1;
		}
	}
	if(F==1){
		ans[0]=1000000000000001;
	}
	for(int i=1;i<=k;i++){
		flag[1]=1;
		sort(edges+2*m+2+2*(k-1)*n,edges+2*m+1+2*k*n,cmp);
		for(int j=1;j<n;j++){
			ans[i]=ans[i]+edges[j].value;
			edges[j].fla=1;
		}
		for(int j=1;j<=n;j++){
			if(flag[j]==0){
				F=1;
			}
		}
		if(F==1){
			ans[i]=1000000000000001;
		}
		if(ans[i]<ans[0]){
			ans[0]=ans[i];
		}
	}
	cout<<ans[0];
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[11][10100],fa[10101],sum,tot[20],u,v,w;
struct ly{
	int u,v,w,zhen;
};
struct cmp{
	bool operator()(ly &a,ly &b)const{
		return a.w>b.w;
	}
};
int find(int x){
	if(x!=fa[x]){
		return fa[x]=find(fa[x]);
	}
	else return x;
}
priority_queue<ly,vector<ly>,cmp>q,q1;
int con[20],ban[20],cnt;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q.push({u,v,w,0});
		q1.push({u,v,w,0});
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		sum+=c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				q.push({j,l,c[i][j]+c[i][l],i});
			}
		}
	}
	while(q.size()){
		ly f=q.top();
		q.pop();
		if(find(f.u)!=find(f.v)){
			fa[fa[f.u]]=fa[f.v];
			sum+=f.w;
			con[f.zhen]+=f.w;
		}
	}
	for(int i=1;i<=k;i++){
		if(con[i]<c[i][0])ban[i]=1;
	}
	sum=0;
	for(int i=1;i<=k;i++){
		if(ban[i])continue;
		sum+=c[i][0];
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				q1.push({j,l,c[i][j]+c[i][l],i});
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	while(q1.size()){
		ly f=q1.top();
		q1.pop();
		if(find(f.u)!=find(f.v)){
			fa[fa[f.u]]=fa[f.v];
			sum+=f.w;
		}
	}
	cout<<sum<<endl;
	return 0;
}//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4


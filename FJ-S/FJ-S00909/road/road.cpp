#include<bits/stdc++.h>
#define pp pair<int,pair<int,int>>
#define sd second
#define ft first
using namespace std;
int n,m,k,val[12],vis[12],fa[140002],flag[12],b[12],is[140002];
long long ans,sum=1,s[12];

int fd(int x){
	if(fa[x]==x)	return x;
	else	return fa[x]=fd(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	priority_queue<pp,vector<pp>>q; 
	cin>>n>>m>>k;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n+k*n;i++)	fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		q.push({-w,{v,u}});
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			q.push({-w,{j,j+n*i}});
		}
	}
	while(!q.empty()){
		pp e=q.top();
		q.pop();
		int u=e.sd.ft,v=e.sd.sd;
		if(fd(e.sd.ft)!=fd(e.sd.sd)){
			int r=(v-1)/n;
			ans+=-e.ft;
			fa[fa[u]]=fa[v];
			if(r&&!vis[r]){
				for(int i=1;i<=n;i++){
					q.push({-val[r],{v,r*n+i}});
					vis[r]=1;
				}
			}
			if(u>n&&v>n)	b[r]++;
			else	s[r]+=-e.ft;
			if(v<=n||(is[v]&&u<=n)||(is[u]&&is[v]&&u!=v))sum++;
			if((v>n&&u<=n&&is[v])||(u>n&&v>n&&u!=v&&is[u]&&is[v]))	flag[r]=1;
			if(v>n&&!is[v])	is[v]=1;
			if(sum==n)	break;
		}	
	}
	for(int i=1;i<=k;i++){
		if(!flag[i]&&vis[i])	ans-=s[i];
		if(b[i])
			ans-=b[i]*val[i]-val[i];
		if(b[i]&&!flag[i])	ans-=val[i];
	}
	cout<<ans;
	return 0;
}


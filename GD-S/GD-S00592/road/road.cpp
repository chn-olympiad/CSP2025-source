#include<bits/stdc++.h>
using namespace std; 

int n,m,k,c[20];
vector<pair<int,pair<int,int> > > p;//存边
int fa[10010];
long long ans;
int usd[20];

int fd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=fd(fa[x]);
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){//要修的路 
		int u,v,w;
		cin>>u>>v>>w;
		p.push_back({w,{u,v}});
	} 
	
	//最小生成树 
	if(k==0){
	
	int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++){
		int u=p[i].second.first;
		int v=p[i].second.second;
		int w=p[i].first;
		int fu=fd(u),fv=fd(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=(long long)w;
			cnt++;
			if(cnt==n-1)break;
		}
	} 
	cout<<ans;
	return 0;
	
	}
	
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			p.push_back({w+c[i],{i+n,j}});
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
//	sort(p.begin(),p.end());
//	for(int i=0;i<p.size();i++){
//		int u=p[i].second.first;
//		int v=p[i].second.second;
//		if(u>n && !usd[u]){
//			p[i].first+=c[u-n];
//			usd[u]=1;
//		}
//		if(v>n && !usd[v]){
//			p[i].first+=c[v-n];
//			usd[v]=1;
//		}
//	} 
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++){
		int u=p[i].second.first;
		int v=p[i].second.second;
		int w=p[i].first;
		int fu=fd(u),fv=fd(v);
		if(fu!=fv){
			if(u>n && !usd[u-n])cnt--;
			if(u>n)usd[u-n]++;
			//
//			cout<<u<<' '<<v<<endl;
			//
			fa[fu]=fv;
			ans+=(long long)w;
			cnt++;
			if(cnt==n-1)break;
		}
	} 
	for(int i=1;i<=k;i++){
		if(usd[i])ans-=(usd[i]-1)*c[i];
	}
	cout<<ans;
	
	return 0;
} 

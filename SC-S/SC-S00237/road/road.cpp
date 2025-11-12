#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e16,sum=0,qd[100055],ds;
vector<long long> mp[100055];
vector<long long> fy[100055];
bool bu[100055],vis[100055];
struct st{
	long long w;
	long long u,v;
};bool pd(st x,st y){
	return x.w<y.w;
}
void dfs(long long nn,long long mm){
	if(nn<=k){
		dfs(nn+1,mm+1);
		bu[n+nn]=1;
		dfs(nn+1,mm);
		bu[n+nn]=0;
		return;
	}sum=0;ds=0;
	for(long long i=n+1;i<=n+k;i++){
		sum+=(!bu[i])*qd[i];
	}
	vector<st> q;
	for(long long i=0;i<mp[1].size();i++){
		st s1; 
		s1.u=1;
		s1.v=mp[1][i];
		s1.w=fy[1][i];
		q.push_back(s1);
	}for(long long i=1;i<=n+k;i++){
		vis[i]=0;
	}vis[1]=1;ds++;
	for(long long g=1;g<n+mm;g++){
		sort(q.begin(),q.end(),pd);
		long long i=0;
		for(;i<q.size();i++){
			if(vis[q[i].v]) continue;
			if(bu[q[i].v]) continue;
			break;
		}//if(bu[5]==0&&bu[6]) cout<<q[i].u<<" "<<q[i].v<<" "<<q[i].w<<endl;
		vis[q[i].v]=1;sum+=q[i].w;ds++;
		for(long long j=0;j<mp[q[i].v].size();j++){
			st s1; 
			s1.u=q[i].v;
			s1.v=mp[q[i].v][j];
			s1.w=fy[q[i].v][j];
			q.push_back(s1);
		}
	}if(sum<ans) ans=sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	long long v,u,w;
	for(long long i=1;i<=m;i++){
		cin >> v >> u >> w;
		mp[v].push_back(u);
		fy[v].push_back(w);
		mp[u].push_back(v);
		fy[u].push_back(w);
	}for(long long i=1;i<=k;i++){
		cin >> v;qd[n+i]=v;
		for(long long j=1;j<=n;j++){
			cin >> w;
			mp[n+i].push_back(j);
			fy[n+i].push_back(w);
			mp[j].push_back(n+i);
			fy[j].push_back(w);
		}
	}
	
	dfs(1,0);cout<<ans;
	return 0;
}
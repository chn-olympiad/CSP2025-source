#include<bits/stdc++.h>
#define int long long
using namespace std;
struct h{
	int u,v,x;
};
int fa[10010];
int ff(int x){
	if(fa[x]==x)return x;
	return fa[x]=ff(fa[x]);
}
void merge(int x,int y){
	fa[ff(x)]=ff(y);
	return;
}
priority_queue<pair<int,int> >f,g;
int n,m,k,ans=0x3f3f3f3f3f3f3f3f,c[35];
vector<h>v;
vector<pair<int,int> >d[10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int s,t,x;
		cin>>s>>t>>x;
		v.push_back({s,t,x});
		f.push({-x,i});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			v.push_back({i+n,j,x});
			d[i].push_back({-x,v.size()-1});
		}
	}
	for(int i=0;i<(1<<k);i++){
		g=f;
		int res=0,s=n-1;
		for(int j=1;j<=k;j++){
			if((1<<j-1)&i){
				res+=c[j];
				for(int t=0;t<n;t++){
					g.push(d[j][t]);
				}
				s++;
			}
		}
		for(int j=1;j<=n+k;j++)fa[j]=j;
		while(!g.empty()&&s){
			h r=v[g.top().second];
			if(ff(r.u)!=ff(r.v)){
				res+=r.x;
				merge(r.u,r.v);
				s--;
			}
			g.pop();
		}
		ans=min(res,ans);
		//cout<<res<<' ';
	}
	cout<<ans;
	return 0;
}

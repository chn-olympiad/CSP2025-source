#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=10055,M=1e6+5;

struct gg{
	int u,v,w;
}a[M],s[15][N];

bool cmp(gg a,gg b){
	return a.w<b.w;
}

long long n,m,k,fa[N],ans=1e18,xdd,ll[15],res,c[15];
priority_queue<pair<int,int>> p;

int find(int o){
	return (fa[o]==o)?o:(fa[o]=find(fa[o]));
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>s[i][j].w,s[i][j].u=i+n,s[i][j].v=j;
	}
	for(int i=1;i<=k;i++) sort(s[i]+1,s[i]+n+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(find(a[i].u)!=find(a[i].v)) a[++xdd]=a[i],fa[find(a[i].u)]=find(a[i].v);
	a[n]={1,1,1000000000};
	for(int i=1;i<=n;i++) s[0][i]=a[i];
	for(int w=0;w<(1<<k);w++){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=0;i<=k;i++) ll[i]=1;
		res=0;
		p.push({-s[0][1].w,0});
		for(int i=1;i<=k;i++) if(w&(1<<i-1)) p.push({-s[i][1].w,i}),res+=c[i];
		int u,v;
		while(!p.empty()){
			int o=p.top().second;
			p.pop();
			u=s[o][ll[o]].u,v=s[o][ll[o]].v;
			if(find(u)!=find(v)){
				res+=s[o][ll[o]].w;
				fa[find(u)]=find(v);
//				cout<<u<<" "<<v<<" "<<s[o][ll[o]].w<<"jj\n"; 
			}
			ll[o]++;
			if(ll[o]<=n) p.push({-s[o][ll[o]].w,o});
		}
//		cout<<w<<" "<<res<<"\n";
		ans=min(ans,res);
	}
	cout<<ans;
}



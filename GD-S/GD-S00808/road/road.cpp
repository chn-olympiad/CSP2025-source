#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[10050],a[10010];
signed mp[10010][10010];
struct node{int u,v,w;};
vector<node> r;
void init(int x){for(int i=1;i<=x;i++) f[i]=i;}
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
void merge(int x,int y){f[find(x)]=find(y);}
bool same(int x,int y){return find(x)==find(y);}
bool cmp1(node x,node y){return x.w<y.w;}
void work(){
	sort(r.begin(),r.end(),cmp1);
	int ans=0,num=n;
	for(node rd:r){
		if(same(rd.u,rd.v)) continue;
		ans+=rd.w;
		merge(rd.u,rd.v);
		num--;
		if(num==1) break;
	} 
	cout<<ans<<'\n';
}
void work1(){
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		r.push_back({x,y,z});
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++)
			cin>>x;
	}
	work();
}
void work2(){
	int x,y,z;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=1e9;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		mp[x][y]=mp[y][x]=min((long long)mp[x][y],z);
	}
	for(int t=1;t<=k;t++){
		cin>>x;
		for(int j=1;j<=n;j++)
			cin>>a[j];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				mp[i][j]=min((long long)mp[i][j],a[i]+a[j]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			r.push_back({x,y,mp[i][j]});
	work();
}
signed main(){
	std::ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n);
	if(k==0) work1();
	else work2();
	return 0;
}

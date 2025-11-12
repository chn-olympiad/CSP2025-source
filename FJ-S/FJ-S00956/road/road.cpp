#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define int long long
#define N 10005
using namespace std;
int n,m,k,ans,mor;
struct node{
	int u,v,w,id;
};
vector<node> a;
int c[N],mw[15];
int f[N*2];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)
		return;
	f[fy]=fx;
}
bool cmp(node x,node y){
	return x.w<y.w; 
}
int Kruskal_(int nn){
	int res=0,cnt=0;
	sort(a.begin(),a.end(),cmp);
	for(int i=1;i<=nn;i++)
		f[i]=i;
	for(int i=0;i<a.size();i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)!=find(v)){
			res+=w;
			merge(u,v);
			cnt++;
			if(cnt==nn-1){
				a.erase(a.begin()+i+1,a.end());
				return res;
			}
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		a.push_back({u,v,w,0});
	}
	ans=Kruskal_(n);
	for(int i=1;i<=k;i++){
		cin>>mw[i];
		for(int j=1;j<=n;j++)
			cin>>c[j];
		for(int j=1;j<=n;j++)
			a.push_back({j,n+i,c[j],i});
		int nw_=Kruskal_(n+mor+1)+mw[i];
		if(nw_<=ans){
			ans=nw_;
			mor++;
		}else{
			for(int j=0;j<a.size();j++){
				if(a[j].id==i)
					a.erase(a.begin()+j);
			}
		}
	}
	cout<<ans;
	return 0;
}

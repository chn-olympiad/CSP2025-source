#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
vector<int> fa;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
struct Road{
	int u,v,w;
};
vector<Road> r;
struct City{
	int c;
	vector<int> a;
};
vector<City> ct;
bool cmp(Road a,Road b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	r.resize(m+1);
	ct.resize(k+1,{0,vector<int>(n+1,0)});
	for(int i=1;i<=n;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>ct[i].c;
		for(int j=1;j<=n;j++){
			cin>>ct[i].a[j];
		}
	}
	if(k==0){
		fa.resize(n+1,0);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(r.begin()+1,r.end(),cmp);
		for(int i=1;i<=m;i++){
			int fu=find(r[i].u),fv=find(r[i].v);
			if(fu!=fv){
				merge(r[i].u,r[i].v);
				ans+=r[i].w;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

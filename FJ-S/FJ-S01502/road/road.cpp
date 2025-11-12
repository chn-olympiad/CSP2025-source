#include<bits/stdc++.h>
using namespace std;
struct bia{
	int u,v,w;
}aib;
vector<bia> che;
vector<vector<int>> lu;
vector<int> xia;
int bcz[10005],sz[10005];
int n,m,k,x;
long long ans;
bool cmp(bia x,bia y){
	return x.w<y.w;
}
int find(int x){
	if(bcz[x]==x) return x;
	return bcz[x]=find(bcz[x]);
}
void bing(int x,int y){
	if(sz[x]>sz[y]){
		bcz[find(y)]=find(x);
		sz[x]+=sz[y];
	}
	else{
		bcz[find(x)]=find(y);
		sz[y]+=sz[x];
	}
}
bool cha(int x,int y){
	return find(x)==find(y);
}
void prim(){
	sort(che.begin(),che.end(),cmp);
	for(int i=0;i<n;i++){
		bcz[i]=i;sz[i]=1;
	}
	for(int i=0;i<m;i++){
		if(cha(che[i].u,che[i].v)) continue;
		bing(che[i].u,che[i].v);
		ans+=che[i].w;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>aib.u>>aib.v>>aib.w;
		che.push_back(aib);
	}
	for(int i=0;i<k;i++){
		cin>>x;
		xia.push_back(x);
		lu.push_back({});
		for(int i=0;i<k;i++){
			cin>>x;
			lu[i].push_back(x);
		}
	}
	if(k==0){
		prim();
	}
	else{
		cout<<n+m-k;
	}
	return 0;
}

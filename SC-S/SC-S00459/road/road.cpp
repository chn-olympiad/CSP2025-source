#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=1e5+5,M=1e6+5,hsh=239;
struct node{
	int u,v,w;
}mp[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int n,m,k;
int kr(){
	int ans=0;
	for(int i=1;i<=2*m;i++){
		if(find(mp[i].u)==find(mp[i].v))continue;
		f[find(mp[i].u)]=find(mp[i].v);
		ans+=mp[i].w;
//		cout<<mp[i].u<<" "<<mp[i].v<<" "<<mp[i].w<<'\n';
	}return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		mp[i*2-1].u=u;mp[i*2-1].v=v;mp[i*2-1].w=w;
		mp[i*2].u=v;mp[i*2].v=u;mp[i*2].w=w;
	}sort(mp+1,mp+1+2*m,cmp);
	cout<<kr();
	return 0;
} 
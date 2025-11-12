#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v,w;
};
vector<node>bian[10100];
long long dian[10100];
long long n,m,k,ans=0;
long long d[10100];
bool v[10100];
bool cmp(node n1,node n2){
	return n1.w<n2.w;
}
void aaa(){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	v[1]=1;
	ans+=d[1];
	for(auto y:bian[1]){
		d[y.v]=min(d[y.v],y.w);
	}
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(v[j]==0){
				if(d[x]>d[j]){
					x=j;
				}
			}
		}
		v[x]=1;
		ans+=d[x];
		for(auto y:bian[x]){
				d[y.v]=min(d[y.v],y.w);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		bian[u].push_back({v,w});
		bian[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>dian[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				bian[j].push_back({k,dian[j]+dian[k]+x});
				bian[k].push_back({i,dian[j]+dian[i]+x});
			}
		}
	}
	aaa();
	cout<<ans;
	return 0;
}

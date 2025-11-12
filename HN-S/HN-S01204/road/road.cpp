#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,k,father[10005],lu[15][10005];
struct information{
	int u,v,w;
};
bool compare(information a,information b){
	return a.w<b.w;
}
vector<information>road;
int find(int x){
	if(father[x]==x)return x;
	father[x]=find(father[x]);
	return father[x];
}
void merge(int a,int b){
	a=find(a),b=find(b);
	father[a]=b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.txt","w",stdout);
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=1;i<=n;++i)father[i]=i;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		road.push_back({u,v,w});
	}
	for(int i=1;i<=k;++i){
		int shuru;
		cin>>shuru;
		for(int j=1;j<=n;++j)cin>>lu[i][j];
		for(int j=2;j<=n;++j)for(int k=1;k<=j;++k)road.push_back({k,j,lu[i][j]+lu[i][k]});
	}
	sort(road.begin(),road.end(),compare);
	int cnt=0,len2=road.size();
	for(int now=0;1+1!=3;++now){
		int tmpu=road[now].u,tmpv=road[now].v;
		if(find(tmpu)==find(tmpv))continue;
		++cnt;
		merge(tmpu,tmpv);
		ans+=road[now].w;
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}

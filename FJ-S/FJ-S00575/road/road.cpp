#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e7+10;
int n,m,k,tot;
map<pair<int,int>,int> mp;
struct edge{
	int u,v,w;
}a[M];
int my[M],vl[M];
int prt[N],c[N],p[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return x==prt[x]?x:prt[x]=find(prt[x]);
}
int kruskal(){
	int sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++)prt[i]=i;	
	for(int i=1;i<=m;i++){
		edge e=a[i];
		int u=e.u,v=e.v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			sum+=e.w;
			prt[fv]=prt[find(fu)];
			cnt++;
		}
		if(cnt==n-1){
			return sum;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		mp[{a[i].u,a[i].v}]=min(a[i].w,mp[{a[i].u,a[i].v}]);
	}
	int sum=0;
	sort(a+1,a+m+1,cmp);
	sum=kruskal();
	if(k==0){
		cout<<sum;
		return 0;
	}
	for(int l=1;l<=k;l++){
		cin>>c[l];
		if(c[l]>sum)continue;
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(p[i]+p[j]>mp[{i,j}])continue;
				a[++m].u=i,a[m].v=j,a[m].w=p[i]+p[j]+c[l];
				mp[{i,j}]=p[i]+p[j];
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	sum=min(sum,kruskal());
	cout<<sum;
	return 0;
}


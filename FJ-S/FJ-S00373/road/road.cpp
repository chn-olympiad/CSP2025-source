#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int vill[15];
long long l,r;
int top,mark,sma=INT_MAX;
struct edges{
	int u,v,w;
}edge[1100010];
int par[10100];
int find(int d){
	return par[d]==d?d:par[d]=find(par[d]);
}
void merge(int x,int y){
	par[find(x)]=find(y);
	return;
}
bool cmp(edges e1,edges e2){
	return e1.w<e2.w;
}
bool check(long long mid){
	long long sum=0;
	for(int i=1;i<=top&&sum<=mid;i++){
		merge(edge[i].u,edge[i].v);
		sum+=edge[i].w;
	}
	int sum2=0;
	for(int i=1;i<=n+k;i++){
		if(par[i]==i)sum2++;
	}
	if(sum2>1){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		top++;
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>vill[i];
		for(int j=1;j<=n;j++){
			top++;
			edge[top].u=n+i;
			edge[top].v=j;
			cin>>edge[top].w;
			if(edge[top].w<sma){
				sma=edge[top].w;
				mark=top;
			}
		}
		edge[mark].w+=vill[i];
	}
	sort(edge+1,edge+top+1,cmp);
	l=0;
	r=2*1e15;
	while(l+1<r){
		for(int i=1;i<=n+k;i++){
			par[i]=i;
		}
		long long mid=l+(r-l)/2;
		if(check(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<r;
	return 0;
}

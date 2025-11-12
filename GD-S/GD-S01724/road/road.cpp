#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
	long long w;
	int id;
}p[1100001];
int n,m,k,fa[10011];
long long c[11];
bool cmp(node x,node y){
	return x.w<y.w;
}
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]); 
}
void merge(int x,int y){
	x=get(x),y=get(y);
	if(x!=y)fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			p[m+i*n+j]={n+i+1,j,w,i+1};
		}
	}
	m=m+k*n;
	n=n+k;
	sort(p+1,p+m+1,cmp);
	long long ans=1e18+7,sum;
	for(int i=0;i<(1<<k);i++){
		sum=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i)sum+=c[j];
		}
		for(int j=1;j<=n;j++){
			fa[j]=j;
		}
		for(int j=1;j<=m;j++){
			if(p[j].id!=0&&((1<<(p[j].id-1))&j)==0)continue;
			if(get(p[j].u)!=get(p[j].v)){
				merge(p[j].u,p[j].v);
				sum+=p[j].w;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

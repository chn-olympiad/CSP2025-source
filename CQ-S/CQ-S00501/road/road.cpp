#include<bits/stdc++.h>
using namespace std;
const int M=1e7+6,N=1e5+5,K=15;int n,m,k,num,ans,fa[M];
struct aaa{int u,v,w;}a[M],g[M];bool qq=1,wx=1;
struct bbb{int p;int q[N];}b[K];
bool cmp(aaa a,aaa b){return a.w<b.w;}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w,fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>b[i].p;if(b[i].p>0)qq=0;
		for(int j=1;j<=n;j++){
			cin>>b[i].q[j];
			if(b[i].q[j]>0)wx=0;
		}
	}if(qq==1&&wx==1){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)
				a[n*i+j].u=n+i,a[n*i+j].v=i,a[n*i+j].w=b[i].q[j];
		}sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
		int u=find(a[i].u),v=find(a[i].v);
			if(u!=v){
				fa[u]=v;
				num++;
				ans+=a[i].w;
			}if(num==n-1)break;
		}cout<<ans;
		return 0;
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			fa[u]=v;
			num++;
			ans+=a[i].w;
		}if(num==n-1)break;
	}cout<<ans;
	return 0;
}

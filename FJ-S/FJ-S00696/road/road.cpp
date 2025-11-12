#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std; 
int n,m,k,id;
struct Road{
	int u,v,w;
}e[2000100];
int fa[2010],v[2010],a[2010];
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
		return fa[x];
	}
	return x;
}
bool cmp(Road x,Road y){
	return x.w<y.w;
}
bool pd(){
	for(int i=2;i<=n;i++){
		if(find(1)!=find(i)){
			return false;
		}
	}
	return true;
}
int kruskal(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	int res=0;
	for(int i=1;i<=id;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		int w=e[i].w;
		if(fu!=fv){
			fa[fu]=fv;
			res+=w;
			if(e[i].u>n){
				if(!v[e[i].u]){
					v[e[i].u]=1;
				}else{
					res-=a[e[i].u-n];
				}
			}
			if(pd()){
				break;
			}
		}
	}
	//------------------------
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(e+1,e+id+1,cmp);
	int ans=0;
	for(int i=1;i<=id;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		int w=e[i].w;
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
			if(e[i].u>n){
				if(!v[e[i].u]){
					v[e[i].u]=1;
				}else{
					ans-=a[e[i].u-n];
				}
			}
			if(pd()){
				break;
			}
		}
	}
	return min(res,ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		id++;
		e[id]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			int b;
			cin>>b;
			id++;
			e[id]={n+i,j,a[i]+b};
		}
	}
//	cout<<"----------------------"<<endl;
	int t=kruskal();
	printf("%lld",t);
	return 0;
}
/*
8 14 1
1 2 7
2 3 6
3 4 4
1 5 9
5 6 9
6 7 1
7 8 1
4 8 8
1 6 8
2 5 7
2 7 2 
3 6 4
3 8 9
4 7 6
5 1 2 3 4 5 6 7 8
*/

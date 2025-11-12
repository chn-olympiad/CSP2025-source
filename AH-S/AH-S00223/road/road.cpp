#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int bk[K];
struct node{
	int x,y,v;
}daolu[M];
bool cmp(node x,node y){
	return x.v<y.v;
}
int fa[N];
int find(int r){
	if(fa[r]==r) return fa[r];
	return fa[r]=find(fa[r]);
}
bool merge(int x,int y){
	int tx=find(x),ty=find(y);
	if(tx!=ty){
		fa[tx]=ty;
		return 1;
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	bool xingzhia=1;
	node in;
	int id=0;
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d%d%d",&in.x,&in.y,&x);
		daolu[++id]={in.x,in.y,x};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&bk[i]);
		int x;
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			daolu[++id]={i,j,x};
		}
		if(bk[i]!=0) xingzhia=0;
	}
		sort(daolu+1,daolu+id+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=id;i++){
			if(merge(daolu[i].x,daolu[i].y)){
				ans=ans+daolu[i].v;
				//printf("%d %d %d\n",daolu[i].x,daolu[i].y,daolu[i].v);
			}
		}
		cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
 */

#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
const int K=15;
int n,m,k;
long long ans=0;

struct Node{
	int x,y,v;
}l[M];
int f[N];
int c[K][N],b[K];
int fa(int x){
	if(f[x]==x)return x;
	return f[x]=fa(f[x]);
}
bool cmp(Node x,Node y){
	if(x.v==y.v){
		if(x.x==y.x)return x.y<y.y;
		return x.x<y.x;
	}return x.v<y.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&l[i].x,&l[i].y,&l[i].v);
	}sort(l+1,l+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&c[i][j]);
	}
	int s=0;
	for(int i=1;i<=m;i++){
		int x=l[i].x,y=l[i].y;
		if(f[x]==f[y])continue;
		
	}
	return 0;
}


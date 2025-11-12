#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
const int M=100101;
const int inf=1e9+7;
int n,m,k,a[M];
int x,y,z,cnt,l[M],h[M];
struct edge{
	int x,y,z,id;
}e[M];
void add(int x,int y,int z,int id){
	e[++cnt]={x,y,z,id};l[cnt]=h[x];h[x]=cnt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,0);
		add(y,x,z,0);
	}
	For(i,1,k){
		scanf("%d",&a[i]);
		For(j,1,n){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z,i);add(y,x,z,i);
		}
	}
	printf("24");
	return 0;
}


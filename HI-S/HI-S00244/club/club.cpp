#include<bits/stdc++.h>
using namespace std;
long long t,n,mans;
struct mem{
	int x,y,z;
}a[1000005];
void dfs(int h,int lenx,int leny,int lenz,long long sum){
	if(h==n+1){
		mans=max(sum,mans);
	}
	if(lenx+1<=n/2){
		dfs(h+1,lenx+1,leny,lenz,sum+a[h].x);
	}
	if(leny+1<=n/2){
		dfs(h+1,lenx,leny+1,lenz,sum+a[h].y);
	}
	if(lenz+1<=n/2){
		dfs(h+1,lenx,leny,lenz+1,sum+a[h].z);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int l=1;l<=n;l++){
			scanf("%d%d%d",&a[l].x,&a[l].y,&a[l].z);
		}
		mans=0;
		dfs(1,0,0,0,0);
		printf("%d\n",mans);
	}
	return 0;
}

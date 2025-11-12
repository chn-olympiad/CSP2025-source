#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],t[100005],e[50],an,id,g[100005],x[100005];
struct node{
	int x,y;
}c[40];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		c[1].x=c[2].x=c[3].x=0;
		c[1].y=1;
		c[2].y=2;
		c[3].y=3;
		id=0;
		an=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			e[1]=a[i][1];
			e[2]=a[i][2];
			e[3]=a[i][3];
			sort(e+1,e+4);
			t[i]=e[3]-e[2];
			if(a[i][1]==e[3]){
				c[1].x++;
				x[i]=1;
			}else if(a[i][2]==e[3]){
				c[2].x++;
				x[i]=2;
			}else{
				c[3].x++;
				x[i]=3;
			}
			an+=e[3];
		}
		sort(c+1,c+4,cmp);
		if(c[3].x>n/2){
			for(int i=1;i<=n;i++){
				if(x[i]==c[3].y){
					id++;
					g[id]=t[i];
				}
			}
			sort(g+1,g+id+1);
			for(int i=1;i<=c[3].x-n/2;i++)an-=g[i];
		}
		printf("%d\n",an);
	}
	return 0;
}

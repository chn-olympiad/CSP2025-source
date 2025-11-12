//mo ni 
#include<bits/stdc++.h>
using namespace std;
int walk[3][2]={{1,0},{0,1},{-1,0}};
int g[105],n,m,cnt=1,cnt2=1;
struct zb{
	int point,x,y;
}a[105];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&g[i]);
	}
	int goal=g[1];
	sort(g+1,g+n*m+1,cmp);
	a[1].x=1;a[1].y=1;a[1].point=g[1];
	for(int i=1;i<=n*m;++i){
		if(i==1){
			continue;
		}
		if(cnt==n){
			a[i].x=a[i-1].x+walk[1][0];
			a[i].y=a[i-1].y+walk[1][1];
			a[i].point=g[i];
			cnt=1;
			cnt2++;
		}
		else if(cnt2%2==1){
			a[i].x=a[i-1].x+walk[0][0];
			a[i].y=a[i-1].y+walk[0][1];
			a[i].point=g[i];
			cnt++;
		}
		else{
			a[i].x=a[i-1].x+walk[2][0];
			a[i].y=a[i-1].y+walk[2][1];
			a[i].point=g[i];
			cnt++;
		}
	}
	int j=1;
	while(true){
		if(a[j].point==goal){
			printf("%d %d",a[j].y,a[j].x);
			return 0;
		}
		j++;
	}
	return 0;
}

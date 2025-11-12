#include <bits/stdc++.h>
using namespace std;
int n,m,u;
struct node{
	int x,y;
}a[105];
bool cmp(node a,node b){return a.x>b.x;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++) scanf("%d",&a[i].x),a[i].y=i;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
		if(a[i].y==1){
			u=i;
			break;
		}
	int c=(u-1)/n+1;
	u-=c*n-n;
	if(c%2==0) u=n-u+1;
	printf("%d %d",c,u);
	return 0;
}

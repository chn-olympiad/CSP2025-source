#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n*m;++i) scanf("%d ",&a[i]);
	int xa=a[1],x=1,y=1;
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==xa) printf("%d %d",y,x);
	else for(int i=2;i<=n*m;++i){
		if((y%2==1&&x>=n)||(y%2==0&&x<=1)) y++;
		else y%2==0?--x:++x;
		if(a[i]==xa){printf("%d %d",y,x);return 0;}
	}
	return 0;
}

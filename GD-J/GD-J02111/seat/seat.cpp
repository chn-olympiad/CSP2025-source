#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],v,b[110],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) {
		scanf("%d",&a[i]);
	}
	v=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++) {
		b[a[i]]=i;
	}
	x=(b[v]-1)/n+1,y=(b[v]-1)%n+1;
	if(x%2==0) y=n-y+1;
	printf("%d %d",x,y);
	
	
	return 0;
}

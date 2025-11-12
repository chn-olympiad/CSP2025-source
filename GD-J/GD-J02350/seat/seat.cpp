//seat
#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,t;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<n*m;i++){
		scanf("%d",&b);
		if(b>a) t++;
	}
	x=t/m,y=t%m;
	if(x&1) y=n-y-1;
	printf("%d %d",x+1,y+1);
	return 0;
}

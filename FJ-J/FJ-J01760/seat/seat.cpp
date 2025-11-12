#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,x,y,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&x);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&y);
		if(y>x)cnt++;
	}
	c=(cnt+n-1)/n;
	if(c%2!=0)r=(cnt%n);
	else r=n-(cnt%n)+1;
	printf("%d %d\n",c,r);
	return 0;
}

#include<bits/stdc++.h>
int n,m,x,y,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&y);
		if(i==1)x=y;
		if(y>=x)cnt++;
	}
//	printf("%d\n",cnt);
	int a=(cnt-1)/n+1;
	printf("%d %d\n",a,a&1?(cnt-1)%n+1:n-((cnt-1)%n));
}
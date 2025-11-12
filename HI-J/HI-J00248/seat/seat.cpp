#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int pos=1;
	scanf("%d",&a);
	int x;
	for(int i=1;i<n*m;i++){
		scanf("%d",&x);
		if(x>a) pos++;
	}
	c=(pos+n-1)/n;
	printf("%d ",c);
	int y=pos%n;
	if(c&1)
		printf("%d",(y%n-n)%n+n);
	else
		printf("%d",((n-y+1)%n-n)%n+n);
	return 0;
}

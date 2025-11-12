#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r,a[20],pos=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]),pos+=a[i]>a[1]?1:0;
	c=pos/n;
	if(pos%n)
		c++;
	r=pos%n==0?n:pos%n;
	if(!(c&1))
		r=n-r+1;
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

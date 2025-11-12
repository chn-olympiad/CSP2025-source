#include<bits/stdc++.h>
using namespace std;
int n,m,a,t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=2;i<=n*m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>a) t++; 
	}
	t++;
	int c=ceil(t*1.0/n),r;
	if(c%2==0) r=n-t%n+1;
	else r=t%n;
	if(r==0) r=n;
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

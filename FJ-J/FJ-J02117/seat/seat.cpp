#include<bits/stdc++.h>
using namespace std;
int a[200],m,n,k=1;
int cc(int x)
{
	return (x-1)/n+1;
}
int rr(int x)
{
	if(cc(x)%2==1) 
	{
		if(x%n==0) return n;
		else return x%n;
	}
	else return n+1-x%n;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1]) k++;
	}
	printf("%d %d",cc(k),rr(k));
	return 0;
}
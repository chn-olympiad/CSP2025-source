#include<bits/stdc++.h>
using namespace std;
int gethang(int x,int n)
{
	x%=(2*n);
	if(x==0) return 1;
	if(x<=n) return x;
	else return 2*n-x+1;
}
int getlie(int x,int n)
{
	if(x%n==0) return x/n;
	else return x/n+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],x=0;
	queue<int> q;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i==1) x=a[i];
	} 
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			printf("%d %d",getlie(i,n),gethang(i,n));
			return 0;
		}
	}
	return 0;
}

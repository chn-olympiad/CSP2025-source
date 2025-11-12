#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

int cmp(int a,int b)
{
	return a>b;
}

int main () 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int tot = 1;
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			int x;
			scanf("%d",&x);
			a[tot++] = x;
		}
	}
	int s = a[1];
	sort(a+1,a+n*m+1,cmp);
	int f = -1;
	for(int i = 1;i < tot;i++)
	{
		if(a[i]==s)
		{
			f = i;
			break;
		}
	}
	if(f%n==0) 
	{
		if((f/n)%2==1) printf("%d %d",f/n,n);
		else printf("%d %d",f/n,1);
	}
	else 
	{
		if((f/n+1)%2==1) printf("%d %d",f/n+1,f%n);
		else printf("%d %d",f/n+1,n-(f%n)+1);
	}
	return 0;
}

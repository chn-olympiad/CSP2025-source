#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			int l=(i+n-1)/n,h=(i-1)%n+1; 
			if(l%2==1)
				printf("%d %d",l,h);
			else
				printf("%d %d",l,n-h+1);
			return 0;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],R;
int c,r;

bool cmp(int s1,int s2)
{
	return s1>s2;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			c=(i+n-1)/n;
			r=(i-1)%n+1;
			if(c%2==0)
				r=n+1-r;
			printf("%d %d",c,r);
		}
	}
	return 0;
}

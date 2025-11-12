#include<bits/stdc++.h>
using namespace std;
int n,m,s,p,k,a[9999];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	s=a[1];k=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(k==1)
			for(int j=1;j<=n;j++)
			{
				p++;
				if(a[p]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else 
			for(int j=n;j>=1;j--)
			{
				p++;
				if(a[p]==s)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		k=(k+1)%2;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[11*11];
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c,d;
	bool bl=false;
	for(int i=1;i<=n*m;i++)
		if(b==a[i])
		{
			c=i;
			break;
		} 
	d=c%n;
	c=(c-d)/n;
	if(d==0)
		bl=true;
	if(c%2==1)
	{
		if(bl) printf("%d %d",c,n);
		else printf("%d %d",c+1,n-d+1);
	}
	else
	{
		if(bl) printf("%d %d",c,1);
		else printf("%d %d",c+1,d);
	}
	return 0;
}

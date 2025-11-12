#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,cn;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			cn=i;
			break;
		}
	}
	int h=cn%n,l=cn/n;
	if(h>0)
	{
		if(l%2==0)h=h;
		else h=n-h+1;
		l++;
	}
	else
	{
		if(l%2==0)h=1;
		else h=n;
	}
	cout<<l<<" "<<h;
	return 0;
}

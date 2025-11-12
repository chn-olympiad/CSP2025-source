#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int er(int o)
{
	int l=1;
	int r=n*m;
	while(r>=l)
	{
		int mid=(r+l)/2;
		if(a[mid]==o)
		{
			return mid;
		}
		if(a[mid]>o)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return 0;
}
bool pie(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	y=a[1];
	sort(a+1,a+n*m+1,pie);
	int s=er(y);
	//the first step;
	int lie=0;
	if(s%n!=0)
	{
		lie=(s/n)+1;
		cout<<lie<<" ";
	}
	else
	{
		lie=s/n;
		cout<<lie<<" ";
	}
	//end;
	//the second step;
	int q=s%n;
	if(q==0)
	{
		q=n;
	}
	//end;
	//the third step;
	int p=lie%2;
	if(p!=0)
	{
		cout<<q;
	}
	else
	{
		cout<<n-q+1;
	}
	return 0;
}

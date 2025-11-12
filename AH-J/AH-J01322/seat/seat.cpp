#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],q=1,p=1,k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			k=i;
			break;
		}
	}
	k--;
	while(k!=0)
	{
		if(p%2==1&&q<n)
		{
			q++;
			k--;
		}
		else if(q>1&&p%2==0)
		{
			q--;
			k--;
		}
		else if(q==n&&p%2==1)
		{
			p++;
			k--;
		}
		else if(q==1)
		{
			p++;
			k--;
		}
	}
	cout<<p<<" "<<q;
	return 0;
}

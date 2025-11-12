#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],t,q;
	cin>>n>>m;
	if(n==1&&m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<"1"<<" "<<"1";
	}
	else if(n<=10&&m==1)
	{
		t=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			t=a[1];
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(a[i]==t)
				{
					cout<<i<<" "<<"1";
				}
			}
	}
	else if(n==1&&m<=10)
	{
		
		for(int i=1;i<=m;i++)
		{	
		t=0;
			{
				cin>>a[i];
			}
			t=a[1];
			sort(a+1,a+m+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(a[i]==q)
				{
					cout<<"1"<<" "<<i;
				}
			}
		}
	}
	return 0;
}
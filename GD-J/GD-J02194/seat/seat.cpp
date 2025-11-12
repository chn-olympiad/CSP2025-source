#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[10000],coin;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	coin=a[0];
	sort(a,a+(n*m),cmp);
	bool head=1;
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		if(head)
		{
			for(int j=0;j<n;j++)
			{
				if(a[cnt]==coin)
				{
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				cnt++;
			}
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				if(a[cnt]==coin)
				{
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				cnt++;
			}
		}
		head=!head;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int b[105],dq=1,qiou,sum=0,y=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	if(n*m==1)
	{
		cout <<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<n*m;i++)
	{
		cin>>b[i];
	}
	int r=b[1];
	sort(b+1,b+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(i%n==0)
		{
			sum=i/n;
		}
		else
		{
			sum=i/n+1;
		}
		if(sum%2==0)
		{
			qiou=0;
		}
		else
		{
			qiou=1;
		}
		if(b[i]==r && i<=n)
		{
			cout <<1<<" "<<n;
			return 0;
		}
		else if(b[i]==r && i>n)
		{
			if(qiou)
			{
				y=i%n;
				if(y==1)
				{
					cout <<sum<<" "<<1;
				}
				if(y==2)
				{
					cout <<sum<<" "<<2;
				}
				if(y==3)
				{
					cout <<sum<<" "<<3;
				}
				if(y==4)
				{
					cout <<sum<<" "<<4;
				}
				return 0;
			}
			else
			{
				y=i%n;
				if(y==1)
				{
					cout <<sum<<" "<<4;
				}
				if(y==2)
				{
					cout <<sum<<" "<<3;
				}
				if(y==3)
				{
					cout <<sum<<" "<<2;
				}
				if(y==4)
				{
					cout <<sum<<" "<<1;
				}
				return 0;
			}
		}
	}
	return 0;
}

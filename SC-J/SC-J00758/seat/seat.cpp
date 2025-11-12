#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
struct node{
	int d;
	bool f;
}x,y;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t;
	cin>>n>>m;
	cin>>a[1];t=a[1];
	for(int i=2;i<=n*m;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i]==t)
		{
			t=i;
		}
	}
	x.d=1;x.f=0;y.d=1;y.f=0;
	for(int i=2;i<=n*m;++i)
	{
		if(x.d==1&&x.f==1)
		{
			++y.d;
			x.f=0;
		}else
		{
			if(x.d==n&&x.f==0)
			{
				++y.d;
				x.f=1;
			}
			else
			{
				if(x.d==n&&x.f==1)
				{
					x.d--;
				}
				else
				{
					if(x.d==1&&x.f==0)
					{
						x.d++;
					}
					else
					{
						if(x.f==0)x.d++;
						if(x.f==1)x.d--;
					}
				}
			}
		}
		if(i==t)
		{
			cout<<y.d<<" "<<x.d;
			return 0;
		}
	}
	cout<<"1 1";
	return 0;
}
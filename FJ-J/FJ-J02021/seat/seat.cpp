#include<bits/stdc++.h> 
using namespace std;
int a[105];
int n,m,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::cin>>n>>m;
	int len=n*m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=len;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+len+1,cmp);
	int t=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[t]==r)
				{
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
				t++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[t]==r)
				{
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
				t++;
			}
		}
	}
	
	return 0;
}

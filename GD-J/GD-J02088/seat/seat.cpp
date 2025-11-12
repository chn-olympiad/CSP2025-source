#include<bits/stdc++.h>
using namespace std;
int n,m;
int r; 
int a[10005];
bool cmp(int q,int w)
{
	return q>w; 
 } 
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(i<=n)
			{
				cout<<1<<" "<<i;
			}
			else
			{
				int t=1;
				while(i>n&&t<m)
				{
					t++;
					i-=n;
				}
				if(t%2)
				{
					cout<<t<<" "<<i;
				}
				else
				{
					cout<<t<<" "<<n-i+1;
				}
			}
			cout<<'\n';
			return 0;
		}
	}
	return 0;
} 

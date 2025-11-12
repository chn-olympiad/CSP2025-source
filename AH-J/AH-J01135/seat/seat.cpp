#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],x,t[N][N],s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m+1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				s--;
				if(a[s]==x)
				{
					cout<<i<<" "<<j<<endl;
					exit(0);
				}
				//cout<<a[s]<<endl;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				s--;
				if(a[s]==x)
				{
					cout<<i<<" "<<j<<endl;
					exit(0);
				}
				//cout<<a[s]<<endl;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	cin>>r;
	int a[15][15];
	int b[105];
	for(int i=1;i<=m*n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+m*n+1);
	for(int i=m*n;i>=1;i--)
	{
		if(r>=b[i] &&r<=b[i-1])
		{
			cout<<i/4+1<<i%4;
		}
	}
		
	return 0;
}

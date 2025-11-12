#include <bits/stdc++.h>
using namespace std;
int m,n,a[10000][10000],r,b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	r=a[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>r) b++;
		}
	}
	b++;
	//b=4;
	//cout<<b<<endl;
	if(b%n==0)
	{
		if(b/n%2==0) cout<<1<<" "<<b/n;
		else cout<<n<<" "<<b/n;
	}
	else
	{
		if((b/n+1)%2==0) cout<<b/n+1<<" "<<n-b%n+1;
		else cout<<b/n+1<<" "<<b%n;
	}
	return 0;
}

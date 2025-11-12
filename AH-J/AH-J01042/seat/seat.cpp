#include<bits/stdc++.h>
using namespace std;
long long a[11][11],b[101];
int n,m,k=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>b[i];
	k=b[1];
	sort(b+1,b+1+n);
	sort(b+1,b+1+m);
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	{   if(a[i][j]==k)
		{
		if(j%2==0)
		cout<<i<<' '<<n-j;
		else
		cout<<i<<' '<<j;
		}
	}
	return 0;
}

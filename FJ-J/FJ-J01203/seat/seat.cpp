#include<bits/stdc++.h>
using namespace std;
int n,m,wz;
int a[110];
int s[10][10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int ma=a[0];
	sort(a,a+(n*m));
	for(int i=m*n-1;i>=0;i--)
	{
		if(a[i]==ma)
		{
			wz=m*n-i;
			break;
		}
	}
	for(int i=0;i<=m*n;i++)
	{
		if(wz<=n && i%2==0)
		{
			cout<<i+1<<" "<<wz;
			break;
		}
		else if(wz<n && i%2==1)
		{
			cout<<i+1<<" "<<n-wz+1;
			break;
		}
		wz-=n;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int f=a[1];
	int ans=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(f==a[i])
		{
			ans=i;
			break;
		}
	}
	if(ans%n==0)
	{
		if((ans/n)%2==1)
		{
			cout << ans/n << " " << n;
		}
		else
		{
			cout << ans/n << " " << 1;
		}
	}
	else
	{
		if((ans/n+1)%2==0)
		{
			cout << ans/n+1 << " " << n-ans%n+1;
		}
		else
		{
			cout << ans/n+1 << " " << ans%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

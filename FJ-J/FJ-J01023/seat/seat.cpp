#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],t,s,ans1,ans2;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int b=n*m;
	for(int i=1;i<=b;i++)
	{
		cin >> a[i];
	}
	t=a[1];
	sort(a+1,a+b+1,cmp);
	for(int i=1;i<=b;i++)
	{
		if(a[i]==t)
		{
			s=i;
		}
	}	
	int j=s/n,k=s%n;
	if(s<=n)
	{
		ans1=1;
		ans2=s;
	}
	else
	{
		if(k==0)
		{
			ans1=j;
			if(ans1%2==0)
			{
				ans2=1;
			}
			else
			{
				ans2=n;
			}
		}
		else 
		{
			ans1=j+1;
			if(ans1%2==0)
			{
				ans2=m+1-k;
			}
			else
			{
				ans2=k;
			}
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
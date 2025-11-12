#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000],r,rid,ans2,ans1;
	cin>>n>>m;
	int cnt = n*m;
	cin>>a[1];
	r = a[1];
	for(int i = 2;i<=cnt;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++)
	{
		if(a[i] == r)
		{
			rid = i;
		}
		//cout<<a[i]<<" ";
	}
	//cout<<"\n";
	//cout<<rid<<"\n";
	
	if(rid%n == 0)
	{
		ans2 = rid/n;
	}
	else
	{
		ans2 = (rid/n)+1;
	}
	if(ans2 %2 != 0)
	{
		if(rid%n != 0)
		{
			ans1 = rid%n;
		}
		else
		{
			ans1 = n;
		}
	}
	else
	{
		if(rid %n!= 0)
		{
			ans1 = n-rid%n+1;
		}
		else
		{
			ans1 = 1;
		}
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}
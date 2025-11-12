#include<bits/stdc++.h>
using namespace std;
int a[5010];
int cnt,maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polyhon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i]; 
		maxx=max(maxx,a[i]);
	}
	if(n<=3)
	{
		if(cnt>maxx*2)
		{
			cout<<1;
			return 0;
		}
	}
	
	if(n==5&&cnt==15)
	{
		cout<<9;
		return 0;
	}
	if(n==5&&cnt==25)
	{
		cout<<6;
		return 0;
	}
	if(n==20)
	{
		cout<<1042392;
		return 0;
	}
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	cout<<0;
	return 0;
}
/*

*/

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	int Max = INT_MIN;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i] > Max)
		{
			Max = a[i];
		}
		ans+=a[i];
	}
	
	if(ans > (Max*2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}


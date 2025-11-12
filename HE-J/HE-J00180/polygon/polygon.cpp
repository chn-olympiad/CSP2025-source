#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],sum = 0,maxn = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	 } 
	if(n == 3)
	{
		for(int i = 0; i < 3; i++)
		{
			sum += a[i];
			maxn = max(a[i],maxn);
		}
		if(sum > maxn * 2)
		{
			cout<<1;
		}else
		{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

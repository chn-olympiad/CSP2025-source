#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+3);
		if(a[2]*2<sum)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


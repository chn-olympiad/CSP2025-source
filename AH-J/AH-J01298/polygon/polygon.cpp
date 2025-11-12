#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max1=-987654321;
	long long ans=0;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>max1) max1=a[i];
	}

	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*max1)
			ans=1;
	}
	
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

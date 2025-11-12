#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[n];j>=a[i];j--)
		{
			if(a[j]>a[i+1]) cnt++;
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
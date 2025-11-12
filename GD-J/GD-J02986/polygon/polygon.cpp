#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	long long ans;
	long long max1=0;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=i;j<n;j++)
		{
			max1=max(a[j],a[j+1]);
			if(cnt>2*max1 && j-i>=2)
			{
				ans++;
			} 
			cnt+=a[j];
		}
	}
	cout<<ans;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

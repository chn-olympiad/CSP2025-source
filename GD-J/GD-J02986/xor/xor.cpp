#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	long long n;
	long long k;
	cin>>n>>k;
	vector<long> r(n);
	long long ans=0;
	long long fc=0;
	for(long long i=0;i<n;i++)
	{
		cin>>r[i];
	}
	for(long long i=fc;i<n;i++)
	{
		long long cnt=r[i];
		for(long long j=i;j<n;j++)
		{
			if(cnt==k)
			{
				ans++;
				fc=j;
				break;
			}
			cnt+=r[j]^r[j+1];		
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

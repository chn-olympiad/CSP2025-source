#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],max1=0,p=0,ans;
pair<long long,long long> qj[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		a[i] ^= a[i-1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(j==i && a[i] == k)
			{
				qj[p].first=i;
				qj[p++].second=i;
				continue;
			}
			if((a[j]^a[i-1]) == k && i!=1 && i != j)
			{
				qj[p].first=i;
				qj[p++].second=j;
				continue;
			}
			if(a[j]==k && i==1 && i != j)
			{
				qj[p].first=i;
				qj[p++].second=j;	
			}
		}
	}
	sort(qj,qj+p);
	long long end=0;
	for(int i = 0;i < p;i++)
	{
		if(qj[i].first>end)
		{
			ans++;
			end = qj[i].second;
		}
	}
	cout<<ans;
	return 0;
}

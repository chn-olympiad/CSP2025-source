#include <bits/stdc++.h>
using namespace std;
int a[1145141];
int sum[1145141],s[1145141];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int last=1,ans=0;
	s[0]++;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(s[sum[i]^k])
		{
			ans++;
			for(int j=last;j<i;j++)s[sum[j]]--,sum[j]=0;
			sum[i]=0;
			last=i+1;
		}
		else s[sum[i]]++;
	}
	cout<<ans;
	return 0;
}

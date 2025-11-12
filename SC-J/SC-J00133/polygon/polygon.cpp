#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie();cin.tie();
	int n;cin>>n;vector<int> a(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	vector<int> b;int l=0,r=n-1,cur=1;
	for(int i=1;i<=n;i++)b.push_back(i);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int k=l;k<=r;k++)
			{
				if(b[k]/cur > j)
				{
					b.push_back(j*cur*10+b[k]);
					//cout<<i<<" "<<j<<" "<<b[k]<<" "<<cur<<"\n";
					//cout<<l<<" "<<r<<"\n";
				}
			}
		}
		cur*=10;
		l=r+1;r=b.size()-1;
	}
	long long ans=0;
	for(long long i=0;i<b.size();i++)
	{
		int num=b[i],sum=0;
		int mx = a[num%10];
		while(num>0)
		{
			sum+=a[num%10];
			num/=10;
		}
		if(mx*2 < sum)
		{
			ans++;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
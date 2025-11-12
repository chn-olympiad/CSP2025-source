#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,h=0;
	vector<long long> s;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long a;cin>>a;
		s.push_back(a);
	}
	sort(s.begin(),s.end());
	for(long long i=1;i<2<<(n-1);i++)
	{
		vector<long long> ans;
		long long hh=0,x=0;     
		for(long long j=i;j>0;j=j>>1) 
		{                                  
			if(j&1)
			{
				hh+=s[x];
				ans.push_back(s[x]);
			}
			x++;
		}
		if(ans.size()>=3&&ans[ans.size()-1]*2<hh)
		{
			h++;
		}
	}
	cout<<h%998244353;
	return 0;
}


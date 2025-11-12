#include<bits/stdc++.h>
using namespace std;

auto time__=time(0)+12356;

struct f
{
	size_t operator() (const int x) const
	{
		return x^time__;
	}
};

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	vector<int> xorsum(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	xorsum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		xorsum[i]=(xorsum[i-1]^arr[i]);
	}
	
	unordered_map<int,bool,f> s;
	s[0]=1;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s.find(xorsum[i]^k)!=s.end())
		{
			cnt++;
			s.clear();
		}
		s[xorsum[i]]=1;
	}
	cout<<cnt;
	return 0;
}

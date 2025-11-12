#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<ull>tt;
bool pd()
{
	if(tt.size()<3)
	{
		return false;
	}
	ull ma=0;
	for(ull q=0;q<tt.size()-1;q++)
	{
		ma+=tt[q];
	}
	return ma>tt[tt.size()-1];
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ull n,sz[5010]={0},ans=0,tp=0;
	cin>>n;
	for(ull q=0;q<n;q++)
	{
		cin>>sz[q];
		if(sz[q]==1)
		{
			tp++;
		}
	}
	if(tp==n)
	{
		for(ull q=3;q<=n;q++)
		{
			ull tmp=1;
			for(ull w=n-q+1;w<=n;w++)
			{
				tmp=(tmp*w)%998244353;
			}
			for(ull w=1;w<=q;w++)
			{
				tmp/=w;
			}
			ans=(ans+tmp)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(sz,sz+n);
	for(ull q=0;q<(1LL<<n);q++)
	{
		for(ull w=0;w<n;w++)
		{
			if((1<<w)&q)
			{
				tt.push_back(sz[w]);
			}
		}
		if(pd())
		{
			ans=(ans+1)%998244353;
		}
		tt.clear();
	}
	cout<<ans;
	return 0;
} 

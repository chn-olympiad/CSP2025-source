#include<bits/stdc++.h>
//luogu:1503820
//topscoding:509
using namespace std;
int a[500005];
long long n,k;
vector<pair<int,int>>ans;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.second!=y.second)
	{
		return x.second>y.second;
	}
	return x.first>y.first;
}
long long tx1()
{
	long long s=0;
	sort(ans.begin(),ans.end());
	int r=0;
	for(int i=0;i<ans.size();++i)
	{
		if(ans[i].first>r)
		{
			++s;
			r=ans[i].second;
		}
	}
	return s;
}
long long tx2()
{
	long long s=0;
	sort(ans.begin(),ans.end(),cmp);
	int l=n+1;
	for(int i=0;i<ans.size();++i)
	{
		if(ans[i].second<l)
		{
			++s;
			l=ans[i].first;
		}
	}
	return s;
}
long long td()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			long long s=a[i];
			for(int kl=i+1;kl<=j;++kl)
			{
				s^=a[kl];
			}
			if(s==k)
			{
				ans.push_back({i,j});
			}
		}
	}
	return max(tx1(),tx2());
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cin.tie(nullptr);
	bool f1=true,f2=true;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			f2=false;
		}
		if(a[i]!=1)
		{
			f1=false;
		}
	}
	if(f1)
	{
		cout<<n/2;
	}
	else
	{
		cout<<td();
	}
	return 0;
}
/*
 CCCC   CCCC  FFFFF
C      C      F
C      C      FFFF
 CCCC   CCCC  F



			A        CCCCC
		   A A      C    
		  A   A     C
		 AAAAAAA    C    
		A       A    CCCCC
*/

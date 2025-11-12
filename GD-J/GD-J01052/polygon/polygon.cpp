#include <bits/stdc++.h>
using namespace std;
int n,s=0;
vector<int> a;
jjf(int bs,int sum,int b,int mx,int ai)
{
	if(bs<b)
	{
		for(int i=ai+1;i<n;i++)
		{
			jjf(bs+1,sum+a[i],b,max(mx,a[i]),i);
		}
		return s%998244353;
	}
	else
	{
		if(sum-mx>mx)
		{
			s+=1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(int i=n;i>=3;i--)
	{
		jjf(0,0,i,-1,-1);
	}
	cout<<s;
	return 0;
}

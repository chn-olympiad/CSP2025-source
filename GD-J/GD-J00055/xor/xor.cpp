#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,dp[500005],num;
struct node{
	long long l,r;
};
node x;
vector<node> v;
bool cmp(node xk,node yk)
{
	if(xk.l==yk.l)
	{
		return xk.r<yk.r;
	}
	return xk.l<yk.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			x.l=i;
			x.r=i;
			v.push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=a[i];
			for(int p=i+1;p<=j;p++)
			{
				ans=ans^a[p];
			}
			if(ans==k)
			{
				x.l=i;
				x.r=j;
				v.push_back(x);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	num=0;
	for(int i=0;i<v.size();i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(v[i].l>v[j].l&&v[i].r>v[j].r&&v[i].l>v[j].r)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		num=max(num,dp[i]);
	 } 
	cout<<num;
	return 0;
} 

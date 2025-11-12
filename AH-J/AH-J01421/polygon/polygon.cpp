#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
vector<int> u;
int ans=0;
bool check()
{
	vector<int> v;
	v=u;
	int sum=0;
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++)
	{
		sum+=a[v[i]];
	}
	return sum>2*a[v[0]];
}
void find(int s,int m)
{
	u.push_back(s);
	if(m==1)
	{
		if(check())
		{
			ans++;
		}
		u.pop_back();
		return;
	}
	for(int i=s+1;i<=n;i++)
	{
		find(i,m-1);
	}
	u.pop_back();
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool i1=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) i1=0;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(i1)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			find(j,i);
		}
	}
	cout<<ans;
	return 0;
}

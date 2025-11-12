#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long p=998244353,n;
vector<long long> a(5010,0),b;
bool check(vector<long long> x)
{
	long long sum=0,maxx=-1;
	for(long long i=0;i<x.size();i++)
	{
		sum+=x[i];
		maxx=max(maxx,x[i]);
	}
	if(sum>2*maxx) return true;
	else return false; 
}
long long dfs(long long id,vector<long long> futrue)
{
	if(id==n+1) return 0;
	vector<long long> x,y;
	long long t=0;
	x=futrue,y=futrue;
	y.push_back(a[id]);
	t=(t+dfs(id+1,x))%p;
	if(check(y)) t=(t+1+dfs(id+1,y))%p;
	else t=(t+dfs(id+1,y))%p;
	return t;
}
long long quick_power(long long a,long long b,long long q)
{
	long long res=1;
	while(b!=0)
	{
		if(b&1) res=res*a%q;
		a=a*a%q,b>>=1;
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(cnt==n)
	{
		cout<<(quick_power(2,n,p)-1-n-n*(n-1)/2+4*p)%p;
		return 0;
	}
	if(n<=20)
	{
		cout<<dfs(1,b);
		return 0;
	}
	cout<<0;
	return 0;
}

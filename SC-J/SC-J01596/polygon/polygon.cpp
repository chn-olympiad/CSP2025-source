#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,mod=998244353;
int n,a[N],ans,b[N],cnt;
//vector<int>v;
bool flag=1;
set<int>s;
signed p(int x)
{
	int res=1;
	for(int i=1;i<=x;i++)
		res*=2;
	return res;
}
void dfs(int id,int sum,int maxx,int num)
{
	if(cnt>5e6)
	{
		cout<<ans;
		exit(0);
	}
	if(id>=3)
	{
		if(sum>2*maxx&&s.count(num)==0)
		{
			ans++;
			ans%=mod;
//			for(int i=0;i<v.size();i++)
//				cout<<v[i]<<' ';
//			cout<<'\n';
			s.insert(num);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)	continue;
		b[i]=1;
//		v.push_back(a[i]);
		dfs(id+1,sum+a[i],max(maxx,a[i]),num+p(i));
//		v.pop_back();
		b[i]=0;
	}
	return;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)	flag=0;
	}
	if(flag)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=(ans*2)%mod;
		ans=ans-n-(n*(n-1)/2%mod)-1;
	}
	else
		dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

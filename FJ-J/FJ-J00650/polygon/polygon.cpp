#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD=998244353;
vector<int> a;
bool vis[5100]={false};
vector<int> v;
int cnt=0;
void dfs(int n,int q,int x,int idx)
{
	if(x>q)
	{
		int sum=0;
		for(auto i:a) sum+=v[i];
		if(sum>v[a[a.size()-1]]*2)
		{
			cnt++;
			cnt%=MOD;
		}
		return;
	}
	for(int i=idx;i<=n;i++)
	{
		if(!vis[i])
		{
			a.push_back(i);
			vis[i]=true;
			dfs(n,q,x+1,i+1);
			a.pop_back();
			vis[i]=false;
		}
	}	
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	v.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin()+1,v.end());
	for(int i=3;i<=n;i++)
	{
		dfs(n,i,1,1);
	}
	cout<<cnt;
	return 0;
}

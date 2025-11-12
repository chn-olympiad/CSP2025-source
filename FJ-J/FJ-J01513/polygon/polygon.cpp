#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int l[1000000];
int st[1000000];
vector<int>dd;
int ans=0;
int n;
int dfs(int x,int k,int f)
{
	if(x==k+1)
	{
		int sum=0;
		int maxn=-0x3f3f3f;
		//sort(dd.begin(),dd.end());
		for(auto i:dd)
		{
			sum+=i;
			maxn=max(maxn,i);
			cout<<i<<" ";
		}
		
		if(sum>maxn*2)
		{
			ans++;
			cout<<"aaa";
		}
		cout<<endl;
			
	}
	for(int i=f;i<=n;i++)
	{
		if(st[i]==0)
		{
			st[i]=1;
			dd.push_back(l[i]);
			dfs(x+1,k,f+1);
			st[i]=0;
			dd.pop_back();
		}
	}
}


signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=3;i<=n;i++)
	{
	dfs(1,i,1);
	}
	cout<<ans/5;
	
}

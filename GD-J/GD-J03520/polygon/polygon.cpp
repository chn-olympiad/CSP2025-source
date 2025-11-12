#include<bits/stdc++.h>
using namespace std;
int n,l[5010],ans,cnt;
int mem[5010];
vector<int> v;
void dfs(int now,int sum,int imax)
{
	if (now==n+1)
	{
		if (sum>2*imax)
		{
			ans++;
//			for (int i=0;i<v.size();i++)
//			{
//				cout<<v[i]<<" ";
//			}
//			cout<<endl;
		}
		return ; 
	}
	v.push_back(l[now]);
	dfs(now+1,sum+l[now],max(imax,l[now]));
	v.pop_back();
	dfs(now+1,sum,imax);
}
int main ()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i];
		mem[i]=-1;
	}
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int N,A[5005],ans,S[5005];
void dfs(int x,int sum,int n)
{
	if(x>n)
	{
		return;
	}
	if(sum>A[n]&&x==n)
	{
		ans++;
	}
	dfs(x+1,sum+A[x],n);
	dfs(x+1,sum,n);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>N;
	for(int i=1;i<=N;i++)  
	{
		cin>>A[i];
	}
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++)
	{
		S[i]=S[i-1]+A[i];
	}
	for(int i=3;i<=N;i++)
	{
		if(S[i-1]>A[i])
		{
			dfs(1,0,i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
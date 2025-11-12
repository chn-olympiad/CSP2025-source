#include <bits/stdc++.h> //4
using namespace std;

long long n,a[5005];
const int c=998244353;
long long cnt=0;

void dfs(int step,long long sum,long long maxn)
{
	if (step>n)
	{
		if (sum>maxn*2) 
		{
			cnt++;
			cnt%=c;
		}
		
		return ;
	}
	
	dfs(step+1,sum,maxn); //²»È¡ 
	dfs(step+1,sum+a[step],max(maxn,a[step])); //È¡ 
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	 
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	dfs(1,0,a[1]);
	
	cout<<cnt;
	return 0;
 } 

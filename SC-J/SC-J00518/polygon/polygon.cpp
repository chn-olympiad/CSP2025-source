#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005]={}; 
long long s=0;
	void dfs(int k,int ma,int ans)
	{
		if(k==n+1)
		{
			if(ans>ma*2)
			{
				s++;
				s=s%998244353;
				
			}
			return ;
		}
				dfs(k+1,max(ma,a[k]),ans+a[k]);
				dfs(k+1,ma,ans);
	}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<s;
	return 0;
 } 
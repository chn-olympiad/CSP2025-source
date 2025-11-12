#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int a[5005],f[5005][5005],sum[5005],s[1000][1000],n;
int x[50005];
int cnt;
void dfs(int res)
{
	if(res==n+1)
	{
		int s1=0,max=0;
		for(int i = 1;i<=n;i++)
		{
			if(x[i]==1) 
		    {
		    	s1+=a[i];
		    	max=a[i];
			}
		}
		if(s1>max*2) cnt++;
		cnt=cnt%N; 
		return ;
	}
	x[res] = 0;
	dfs(res+1);
	x[res]=1;
	dfs(res+1);
 } 
int main()
{
	freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]> a[3]) cout<<1;
		else cout<<0;
		return 0;
	}

    dfs(1);
    cout<<cnt;
	return 0;
 } 

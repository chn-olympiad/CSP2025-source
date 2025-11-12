#include<bits/stdc++.h>
using namespace std;
int n,a[5005],path[5005],num;
void dfs(int i,int sum,int mx,int cnt)
{
	if(i==n+1)
	{
		if(cnt>=3 && sum>2*mx){
			num++;
			num%=998244353;
		}
		return;
	}
	dfs(i+1,sum,mx,cnt);
	dfs(i+1,sum+a[i],max(mx,a[i]),cnt+1);
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
	dfs(1,0,0,0);
	cout<<num;
    return 0;
}

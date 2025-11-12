#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll t,n,a[N][5],f[N][5],vis[5],ans;
void dfs(ll d,ll sum)
{
	if(d>n)
	{
		ans=max(ans,sum);
		return ;
	}
	for(ll i=1;i<=3;i++) 
	{
		if(vis[i]<n/2)
		{
			vis[i]++;
			dfs(d+1,sum+a[d][i]);
			vis[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	bool tmp_2,tmp_3;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][2]>0) tmp_2=1;
			if(a[i][3]>0) tmp_3=1;
		}
		if(tmp_2==0&&tmp_3==0)
		{
			for(ll i=1;i<=n;i++)
			{
				ans+=a[i][1];
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";	
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

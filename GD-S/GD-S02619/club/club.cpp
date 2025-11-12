#include<bits/stdc++.h>
using namespace std;

int n,a[3][100001],num[3],b[100001];
long long ans;

void dfs(int pos,long long tans)
{
	if(pos>n)
	{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<b[i]<<" ";
//		}cout<<": "<<tans<<"\n";
		ans=max(tans,ans);
		return   ;
	}
	for(int i=0;i<3;i++)
	{
		if(num[i]<n/2)
		{
//		cout<<i<<" "<<num[i]<<" num\n";
			num[i]++;
			b[pos]=i;
			dfs(pos+1,tans+a[i][pos]);
			num[i]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(num,0,sizeof(num));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[j][i];
			}
		}
		dfs(1,0);
		
		cout<<ans<<"\n";
	}

}


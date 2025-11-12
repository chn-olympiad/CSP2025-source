#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;//Ren5Jie4Di4Ling5%

const int N=1e5,L=3;

int T;
int n;
int a[L+1][N+1];

bool flag;
int ans;

inline void dfs(int pos,int cnt1,int cnt2,int cnt3,int sum)
{
	if(pos>n)
	{
		ans=max(ans,sum);
		return;
	}
	
	if(cnt1+1<=n/2) dfs(pos+1,cnt1+1,cnt2,cnt3,sum+a[1][pos]);
	if(cnt2+1<=n/2) dfs(pos+1,cnt1,cnt2+1,cnt3,sum+a[2][pos]);
	if(cnt3+1<=n/2) dfs(pos+1,cnt1,cnt2,cnt3+1,sum+a[3][pos]);
	
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);

	cin>>T;
	while(T--)
	{
		cin>>n;
		flag=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[j][i],flag&=(a[2][i]==0)&(a[3][i]==0);
		
		if(flag)
		{
			ans=0;
			sort(a[1]+1,a[1]+1+n);
			for(int i=n;i>n/2;i--) ans+=a[1][i];
		}
		else
		{
			ans=0;
			dfs(1,0,0,0,0);
		}
		
		
		cout<<ans<<'\n';
	}

	return 0;
}


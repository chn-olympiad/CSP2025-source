#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][10];
int f[10];
int cnt;
int ans;

void dfs (int c)
{
	if(f[1]>n/2||f[2]>n/2||f[3]>n/2) 
		return ;
	else if(c==n+1) 
	{
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;++i)
	{
		cnt+=a[c][i];
		++f[i];
		dfs(c+1);
		--f[i];
		cnt-=a[c][i];
	}
}

int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		cnt=ans=0;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n==2) cout<<max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
		else 
		{
			dfs(1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}

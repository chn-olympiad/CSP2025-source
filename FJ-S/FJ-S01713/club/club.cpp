#include<bits/stdc++.h>
using namespace std;

int n,t,ans=-0x3f3f3f,sum[100005],r[3],a[100005][3];

void mset() 
{
	for(int i=1;i<=n;i++) a[i][0]=a[i][1]=a[i][2]=0;
	r[0]=r[1]=r[2]=0;
}

void dfs(int nw,int ca,int cb,int cc,int val)
{
	if(nw==n+1)
	{
		ans=max(ans,val);
		return ;
	}
	if(ca<n/2&&val) dfs(nw+1,ca+1,cb,cc,val+a[nw][0]);
	if(cb<n/2&&val) dfs(nw+1,ca,cb+1,cc,val+a[nw][1]);
	if(cc<n/2&&val) dfs(nw+1,ca,cb,cc+1,val+a[nw][2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=-0x3f3f3f;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n<20)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		
		mset();
	}
	return 0;
}
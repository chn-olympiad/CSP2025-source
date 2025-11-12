#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Maxn=1e5+5;
int t,n,ans,a[Maxn][5];
void dp(int x,int y,int z,int now,int num)
{
	now++;
	if(now>n) 
	{
		ans=max(ans,num);
		return ;
	}
	if(x<n/2) dp(x+1,y,z,now,num+a[now][1]);
	if(y<n/2) dp(x,y+1,z,now,num+a[now][2]);
	if(z<n/2) dp(x,y,z+1,now,num+a[now][3]);
	return ;
}
void gowork()
{
	bool flag=1;
	cin>>n;
	priority_queue<int>  q[5];
	int qmx[5],qmn[5];
	for(int i=1;i<=3;i++) qmx[i]=-0x3f,qmn[i]=0x3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) cin>>a[i][j];
		if(a[i][2]||a[i][3]) flag=0; 
	}
	if(flag==1)
	{
		int ans=0,e[Maxn];
		for(int i=1;i<=n;i++) e[i]=a[i][1];
		sort(e+1,e+n+1);
		for(int i=n;i>=n/2+1;i--) ans+=e[i];
		cout<<ans<<'\n';
		return ;
	}
	if(n<=20)
	{
		ans=-1e18;
		dp(0,0,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
	int minn=1e18;
	for(int i=1;i<=n;i++)
	{
		int mx=-1e18,p;
		for(int j=1;j<=3;j++) 
		{
			if(a[i][j]>mx) mx=a[i][j],p=j;
		}
		if(q[p].size()<n/2) 
		{
			q[p].push(-a[i][p]);
			qmx[p]=max(qmx[p],a[i][p]);
			qmn[p]=min(qmn[p],a[i][p]);
			minn=min(minn,qmn[p]);
			continue;
		}
		if(mx<minn) continue;
		int now_mn=qmn[p],l;
		bool flag=1;
		for(int j=1;j<=3;j++)
		{
			if(j==p) continue;
			if(qmn[p]<qmn[j]) flag=0;
			if(now_mn>=qmn[j]) l=j,now_mn=qmn[j];
		}
		if(flag) 
		{
			q[l].pop();
			qmn[l]=(-q[l].top());
		}
		else 
		{
			q[p].pop();
			q[p].push(-a[i][p]);
		}
		qmx[p]=max(qmx[p],a[i][p]);
		qmn[p]=min(qmn[p],a[i][p]);
		for(int j=1;j<=3;j++) minn=min(minn,qmn[j]);
	}
	int ans=0;
	for(int j=1;j<=3;j++)
	{
		while(!q[j].empty()) 
		{
			ans+=(-q[j].top());
			q[j].pop();
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) gowork();
	return 0;
}
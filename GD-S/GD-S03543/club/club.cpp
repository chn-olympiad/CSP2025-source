#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int b,x,y;
}a[300005];
struct nd
{
	int num,x,y;
};
int c[100005][10];
int vis[100005],num[10];
priority_queue<nd> q[10];
bool cmp(node A,node B)
{
	return A.b>B.b;
}
bool operator<(const nd &A,const nd &B)
{
	int num1=1e18;
	for(int i=1;i<=3;i++)
		if(A.y!=i) num1=min(num1,abs(c[A.x][i]-A.num));
	int num2=1e18;
	for(int i=1;i<=3;i++)
		if(B.y!=i) num2=min(num2,abs(c[B.x][i]-B.num));
	return num1>num2;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		num[1]=num[2]=num[3]=0;
		int n,cnt=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			cin>>c[i][1]>>c[i][2]>>c[i][3];
			a[++cnt].b=c[i][1],a[cnt].x=i,a[cnt].y=1;
			a[++cnt].b=c[i][2],a[cnt].x=i,a[cnt].y=2;
			a[++cnt].b=c[i][3],a[cnt].x=i,a[cnt].y=3;
		}
		sort(a+1,a+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			if(vis[a[i].x]) continue;
			q[a[i].y].push({a[i].b,a[i].x,a[i].y});
			num[a[i].y]++;
			ans+=a[i].b;
			vis[a[i].x]=1;
			if(num[a[i].y]>n/2)
			{
				nd t=q[a[i].y].top(); q[a[i].y].pop();
				int numn=1e18,numv;
				for(int j=1;j<=3;j++)
					if(t.y!=j&&numn>abs(c[t.x][j]-t.num))
					{
						numn=abs(c[t.x][j]-t.num);
						numv=j;
					}
				num[a[i].y]--;
				ans-=t.num;
				num[numv]++;
				q[numv].push({c[t.x][numv],t.x,numv});
				ans+=c[t.x][numv];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

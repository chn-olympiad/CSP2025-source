#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define pii pair<int,int>
#define fi first
#define se second

int n;
struct node
{
	pii val[5];
	int id;
}a[N];
pii cha[5];
bool cmp1(pii a,pii b)
{
	return a>b;
}
bool cmp(node n1,node n2)
{
	for(int i=1;i<=3;i++)cha[i]={abs(n1.val[i].fi-n2.val[i].fi),i};
	sort(cha+1,cha+3+1);
	for(int i=3;i>=1;i--)if(cha[i].fi)return n1.val[cha[i].se]>n2.val[cha[i].se];
}
int a1[N][5];

int ans=0;
int sum[5];
int mxed[N];
void dfs(int x,int res)
{
	if(x>n)
	{
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=3;i++)if(sum[i]<n/2&&res+a1[x][i]+mxed[x+1]>ans)
	{
		sum[i]++;
		dfs(x+1,res+a1[x][i]);
		sum[i]--;
	}
}
void solve1()
{
	memset(sum,0,sizeof(sum));ans=0;
	memset(mxed,0,sizeof(mxed));
	
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i][1]>>a1[i][2]>>a1[i][3];
	}
	
	for(int i=n;i>=1;i--)mxed[i]=mxed[i+1]+max(a1[i][1],max(a1[i][2],a1[i][3]));
	dfs(1,0);
	cout<<ans<<'\n';
}
void solve2()
{
	sum[1]=sum[2]=sum[3]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val[1].fi>>a[i].val[2].fi>>a[i].val[3].fi;
		a[i].val[1].se=1;
		a[i].val[2].se=2;
		a[i].val[3].se=3;
		a[i].id=i;
		sort(a[i].val+1,a[i].val+3+1,cmp1);
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(sum[a[i].val[j].se]<n/2)
			{
				ans+=a[i].val[j].fi;
				sum[a[i].val[j].se]++;
				break;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
//	freopen("club4.in","r",stdin);
	
	int t;cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=30)solve1();
		else solve2();
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

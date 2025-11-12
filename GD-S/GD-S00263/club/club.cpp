#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
const int maxn=1e5+114; 
int a[maxn][4],cnt[4],b[maxn][4];
struct node
{
	int v,x;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
} s[4],q[maxn];
void solve()
{
	int n;ll sum=0;
	rep(i,1,3) cnt[i]=0;
	cin>>n;
	rep(i,1,n)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		rep(j,1,3) s[j].v=a[i][j],s[j].x=j;
		sort(s+1,s+4);
		rep(j,1,3) b[i][j]=s[j].x;
		sum+=a[i][b[i][1]];
	}
	rep(i,1,n)
	{
		cnt[b[i][1]]++;
	}
	int maxn=0;
	rep(i,1,3) maxn=max(maxn,cnt[i]);
	if(maxn<=n/2)
	{
		cout<<sum<<'\n';
	}else{
		int rid=0;
		if(cnt[1]>=cnt[2] and cnt[1]>=cnt[3]) rid=1;
		if(cnt[2]>=cnt[1] and cnt[2]>=cnt[3]) rid=2;
		if(cnt[3]>=cnt[1] and cnt[3]>=cnt[2]) rid=3;
		rep(i,1,n)
		{
			q[i].v=a[i][b[i][2]]-a[i][b[i][1]];
			q[i].x=i;
		}
		sort(q+1,q+n+1);
		rep(i,1,n)
		{
			int x=q[i].x;
			if(b[x][1]!=rid) continue;
			cnt[b[x][1]]--;
			cnt[b[x][2]]++;
			sum+=q[i].v;
			if(cnt[rid]<=n/2) break;
		}
		cout<<sum<<'\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c-'0');
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1e5+5;
int n;
int s[4][N],top[4];
int cnt[4];
struct Node{
	int a,id;
} a[N][4];
bool cmp(Node x,Node y) { return x.a>y.a; }
priority_queue<int,vector<int>,greater<int> > q;

void solve()
{
	memset(cnt,0,sizeof(cnt));
	memset(top,0,sizeof(top));
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			a[i][j].a=read();
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+1+3,cmp);
		cnt[a[i][1].id]++;
	}
	int maxn=0;
	for(int i=1;i<=3;i++) maxn=max(maxn,cnt[i]);
	if(maxn<=(n>>1))
	{
		// cout<<"aaa"<<" ";
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][1].a;
		cout<<ans<<"\n";
	}
	else
	{
		while(q.size()) q.pop();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][1].a;
			if(cnt[a[i][1].id]==maxn) q.push(a[i][1].a-a[i][2].a);
		}
		while(q.size()>(n>>1))
		{
			ans-=q.top();
			q.pop();
		}
		cout<<ans<<"\n";
	}
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T=read();
	while(T--) solve();

	return 0;
}
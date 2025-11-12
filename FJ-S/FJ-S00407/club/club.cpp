#include<bits/stdc++.h>
#define int long long
#define R read()
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second 
#define gc getchar
using namespace std;
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=gc();
	return x*f;
}
void write(int x,char xx)
{
	static int st[35],tot=0;
	if(x<0) putchar('-'),x=-x;
	do {st[++tot]=x%10,x/=10;}
	while(x);
	while(tot) putchar('0'+st[tot--]);
	putchar(xx);
}
#define N 100010
int n,a[N][4],cnt[4],b[N][4],X,ans;
bool cmp(int x,int y){return a[X][x]>a[X][y];}
bool cmp1(int x,int y){return a[x][b[x][1]]-a[x][b[x][2]]<a[y][b[y][1]]-a[y][b[y][2]];}
vector<int>v;
void solve()
{
	n=R,cnt[1]=cnt[2]=cnt[3]=ans=0,v.clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) a[i][j]=R,b[i][j]=j;
		X=i,sort(b[i]+1,b[i]+3+1,cmp),cnt[b[i][1]]++,ans+=a[i][b[i][1]];
	}
	if(max({cnt[1],cnt[2],cnt[3]})<=(n>>1)) return write(ans,'\n');
	else
	{
		int id=0;
		for(int i=1;i<=n;i++) if(cnt[b[i][1]]==max({cnt[1],cnt[2],cnt[3]})) v.push_back(i),id=b[i][1];
		sort(v.begin(),v.end(),cmp1);
		for(int i:v)
		{
			ans-=a[i][b[i][1]]-a[i][b[i][2]],cnt[b[i][1]]--,cnt[b[i][2]]++;
			if(cnt[id]<=(n>>1)) break;
		}
		write(ans,'\n');
	}
}
int T=1;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=R;
	while(T--) solve();
	return 0;
}
//14:46 Accepted All Examples
//by syzygy

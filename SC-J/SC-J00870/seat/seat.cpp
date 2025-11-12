#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
#define inline
#define fi first
#define se second
#define sh short
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=1e9+7;
const int MN=1e6+10;
//const ll inf=1e18;
const int inf=1e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

int n,m,x,y,a[MN];

inline bool solve()
{
	cin>>n>>m;for(int i=1;i<=n*m;++i)cin>>a[i];
	x=a[1],sort(a+1,a+n*m+1),x=lower_bound(a+1,a+n*m+1,x)-a,x=n*m-x+1;
	y=(x-1)/n+1,x=(x-1)%n+1;
	if(!(y&1))x=n-x+1;
	cout<<y<<' '<<x<<endl;
	return 0;
}

signed main()
{
	frein(seat);freout(seat);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc .out .ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}
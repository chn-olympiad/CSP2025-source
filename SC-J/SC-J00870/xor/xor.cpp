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

int n,k,a[MN],b[MN],c[MN],s[MN],ne[MN],res[MN];
struct node{int w,ide;}p[MN];

inline bool solve()
{
	cin>>n>>k;for(int i=1;i<=n;++i)cin>>a[i],p[i].ide=i;
	for(int i=1;i<=n;++i)p[i].w=s[i]=s[i-1]^a[i];
	sort(p+1,p+n+1,[&](node &n1,node &n2){return n1.w==n2.w?n1.ide<n2.ide:n1.w<n2.w;});
	for(int i=1;i<=n;++i)b[i]=p[i].w;
	for(int i=1;i<=n;++i)c[i]=p[i].ide;
	for(int i=1,k1=0,k2=0;i<=n;++i)
	{
		k1=lower_bound(b+1,b+n+1,s[i-1]^k)-b;
		k2=upper_bound(b+1,b+n+1,s[i-1]^k)-b-1;
		ne[i]=k1<=k2?lower_bound(c+k1,c+k2+1,i)-c:0;
		ne[i]=ne[i]==k2+1?0:c[ne[i]];
	}
	for(int i=1;i<=n;++i,res[i]=max(res[i],res[i-1]))if(ne[i]!=0)res[ne[i]]=max(res[ne[i]],res[i-1]+1);
	cout<<res[n]<<endl;
	return 0;
}

signed main()
{
	frein(xor);freout(xor);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc xor.out xor1.ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}
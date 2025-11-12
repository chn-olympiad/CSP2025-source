#include<bits/stdc++.h>
//#define int long long
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
#define N 200010
#define bs 1145141
#define ull unsigned long long
const int V=5e6;
int n,Q,l[N],m,ll[N],rr[N],lll,rrr;
ull p[V+10],inv[V+10],op[V+10],po[V+10];
vector<ull>ps[N],pt[N];
ull qpow(ull x,ull y=~0ull)
{
	ull num=1;
	while(y)
	{
		if(y&1) num=num*x;
		x=x*x,y>>=1;
	}
	return num;
}
string s[N],t[N],S,T;
void rd(string &s)
{
	s="";
	char c=gc();
	while(c>'z'||c<'a') c=gc();
	while(c>='a'&&c<='z') s+=c,c=gc();
}
ull qu(vector<ull>&c,int l,int r){return (c[r]-c[l-1])*inv[l-1];}
ull qus(int l,int r){return (op[r]-op[l-1])*inv[l-1];}
ull qut(int l,int r){return (po[r]-po[l-1])*inv[l-1];}
vector<int>v[V+10];
int tot=0;
void solve()
{
	rd(S),rd(T),tot++;
	if(S.length()!=T.length()) return puts("0"),void(0);
	m=S.length(),S=" "+S,T=" "+T,lll=0,rrr=m+1,op[0]=po[0]=0;
	for(int i=1;i<=m;i++) if(S[i]!=T[i]) {lll=i;break;}
	for(int i=m;i>=1;i--) if(S[i]!=T[i]) {rrr=i;break;}
	for(int i=1;i<=m;i++) op[i]=op[i-1]+(S[i]-'a'+1)*p[i];
	for(int i=1;i<=m;i++) po[i]=po[i-1]+(T[i]-'a'+1)*p[i];
	int ans=0;
	for(int i:v[rrr-lll]) ans+=(qu(ps[i],1,l[i])==qus(lll-ll[i]+1,rrr+l[i]-rr[i])&&qu(pt[i],ll[i],rr[i])==qut(lll,rrr));
	for(int i=0;i<=m;i++) op[i]=po[i]=0;
	write(ans,'\n');
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=R,Q=R,p[0]=1;
	for(int i=1;i<=n;i++)
	{
		rd(s[i]),rd(t[i]),l[i]=s[i].length(),ll[i]=-1,rr[i]=l[i]+1,s[i]=" "+s[i],t[i]=" "+t[i];
		for(int j=1;j<=l[i];j++) if(s[i][j]!=t[i][j]) {ll[i]=j;break;}
		for(int j=l[i];j>=1;j--) if(s[i][j]!=t[i][j]) {rr[i]=j;break;}
		if(ll[i]==-1) n--,i--;
		else v[rr[i]-ll[i]].push_back(i);
	}
	for(int i=1;i<=V;i++) p[i]=p[i-1]*bs;
	inv[V]=qpow(p[V]);
	for(int i=V-1;i>=0;i--) inv[i]=inv[i+1]*bs;
	for(int i=1;i<=n;i++) 
	{
		ps[i].resize(l[i]+2),ps[i][0]=0;
		for(int j=1;j<=l[i];j++) ps[i][j]=ps[i][j-1]+(s[i][j]-'a'+1)*p[j];
		pt[i].resize(l[i]+2),pt[i][0]=0;
		for(int j=1;j<=l[i];j++) pt[i][j]=pt[i][j-1]+(t[i][j]-'a'+1)*p[j];
	}
	while(Q--) solve();
	return 0;
}


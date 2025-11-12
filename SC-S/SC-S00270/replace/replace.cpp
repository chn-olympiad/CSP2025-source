#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int maxn=2e5+10;
int n,q;
struct query
{
	string s,t;
} a[maxn];
string s,t;
int ans=0;
int get(string x)
{
	int L=1,R=n,ans=0;
	while(L<=R)
	{
		int mid=(L+R)/2;
		if(a[mid].s>=x) ans=mid,R=mid-1;
		else L=mid+1;
	}
	return ans;
}
void solve(string s,string t)
{
	ans=0;
	int len=s.size();
	int L=0,R=len-1;
	while(s[L]==t[L]&&L<R) L++;
	while(s[R]==t[R]&&L<R) R--;
	for(int i=0;i<=L;i++)
	{
		for(int l=R-i+1;l<=len&&i+l-1<=len-1;l++)
		{
			string x=s.substr(i,l),S=s;
			int pos=get(x);
			for(int	k=pos;a[k].s==x;k++)
			{
				for(int w=i;w<=i+l-1;w++) S[w]=a[k].t[w-i];
				if(S==t) ans++;
			}
		}
	}
}
bool cmp(query x,query y) {return x.s<y.s;}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(); q=read();
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].t;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		solve(s,t);
		cout<<ans<<"\n";
	}
}
//rp++
//finish 17:22
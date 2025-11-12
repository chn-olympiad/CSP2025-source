#include<bits/stdc++.h>
#define MAXN 505
#define ll long long
#define pb push_back
using namespace std;
const ll mod=998244353;
int read()
{
	int ret=0,sgn=0,ch=getchar();
	while(!isdigit(ch)) sgn|=ch=='-',ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn ? -ret:ret;
}
int n,m,ans,c[MAXN],a[MAXN];
char s[MAXN];
bool ok=1;
void solve()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		if (s[i]=='0') ok=0;
	}
	for (int i=1;i<=n;i++) cin>>c[i],a[i]=i;
	if (m==n)
	{
		if (!ok) puts("0");
		else
		{
		ll res=1;
		for (int i=1;i<=n;i++) res=res*i%mod;
		cout<<res;
		return;
		}
		return;
	}
	do
	{
		int lv=0,sum=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='0') lv++;
			else
			{
				if (lv>=c[a[i]]) lv++;
				else sum++;
			}
		}
		ans+=sum>=m;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	for (int i=1;i<=T;i++) solve();
	return 0;
}

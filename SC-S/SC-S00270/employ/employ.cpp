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
const int maxn=510;
int n,m,ans;
char s[maxn];
int c[maxn],p[maxn];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	cin>>(s+1);
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[p[i]]<=cnt) cnt++;
		}
		if(n-cnt>=m) ans++;
	} while(next_permutation(p+1,p+1+n));
	cout<<ans<<"\n";
}
//rp++
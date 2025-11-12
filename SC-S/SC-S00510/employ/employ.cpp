#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<ull,ull>
#define fi first
#define se second
using namespace std;

inline int read()
{
	int x=0,fu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}

void write(int x)
{
	if(x<0){putchar('-'),x=-x;}
	if(x<10){putchar(x+'0');return;}
	write(x/10);putchar(x%10+'0');
}

const int N=510,mod=998244353;
int a[N];
int sum[N];
int n,m;
char s[N];
//namespace case1
//{
//	void solve()
//	{
//		int ans=1;
//		for(int i=1;i<=n;i++)	ans=ans*i%mod,cout<<i<<" "<<ans<<endl;
//		write(ans);
//	}
//}
bool sg[N];
int p[N];
int ans;
void dfs(int x,int res,int tot)
{
	if(x==n+1)
	{
		if(res>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(sg[i])	continue;
		p[x]=i;
		if(a[i]<=tot||s[x]=='0')	tot++;
		else	res++;
		sg[i]=true;
//		for(int i=1;i<=x;i++)	cout<<p[i]<<" ";
//		cout<<endl;
//		cout<<(a[i]<=tot||s[i]=='0')<<" "<<a[i]<<" "<<tot<<" "<<s[i]<<endl;
		dfs(x+1,res,tot);
		if(a[i]<=tot||s[x]=='0')	tot--;
		else	res--;
		sg[i]=false;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)	a[i]=read();
	dfs(1,0,0);
	write(ans);
	return 0;
}
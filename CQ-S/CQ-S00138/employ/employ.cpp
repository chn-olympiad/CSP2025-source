#include<bits/stdc++.h>
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define ff(i,a,b) for(int i=(a);i>=(b);i--)
#define sd std::
#define dbg(x) sd cout<<#x<<":"<<x<<" "
#define dg(x) sd cout<<#x<<":"<<x<<"\n"
#define inf 1e10
int read(){int w=1,c=0;char ch=getchar();for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;for(;ch>='0'&&ch<='9';ch=getchar()) c=(c<<3)+(c<<1)+ch-48;return w*c;}
void printt(int x){if(x>9) printt(x/10);putchar(x%10+48);}
void print(int x){if(x<0) putchar('-'),x=-x;printt(x);}
void printk(int x){print(x);putchar(' ');}
void put(int x){print(x);puts("");}
const int N=1e5+10,P=998244353;
int n,m,c[N];
char s[N];
void fre()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int ans,vis[N],p[N];
void dfs(int x)
{
	if(x>n)
	{
		int now=0,sum=0;
//		F(i,1,n) printk(p[i]);
//		puts("");
		F(i,1,n)
		{
			if(now>=c[p[i]])
			{
				now++;
				continue;
			}
			if(s[i]=='1')
				sum++;
			else now++;
		}
		if(sum>=m) ans++;
		return;
	}
	F(i,1,n)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve()
{
	n=read();m=read();
	scanf("%s",s+1);
	F(i,1,n) c[i]=read();
	if(n<=10)
	{
		dfs(1);
		put(ans%P);
		return;
	}
	ans=1;
	F(i,1,n) ans=ans*i%P;
	put(ans);
}
signed main()
{
	fre();
	int T=1;
//	T=read();
	while(T--) solve();
}



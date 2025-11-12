#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		f=(ch=='-'?-1:f);
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
void writech(ll x,char ch)
{
	write(x);
	putchar(ch);
}
const ll mod=998244353;
int a[510],s[510],op[18];
struct node{
	int val,cnt;
}rmg[(1<<18)];
unsigned ll dp[(1<<18)][18];
bool cmp(node x,node y)
{
	return x.cnt<y.cnt;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();	
	string t;
	cin>>t;
	for(int i=1;i<=n;i++)
	{
		s[i]=t[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
			rmg[i].val=i;
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1)rmg[i].cnt++;
			}
		}
		sort(rmg,rmg+(1<<n),cmp);
		for(int _=1;_<(1<<n);_++)
		{
			int i=rmg[_].val,cnt=0;
//			cout<<i<<' ';
			for(int j=0;j<n;j++)
			{
				op[j]=((i>>j)&1);
				if(op[j])cnt++;
			}
//			cout<<cnt<<' ';
			for(int j=0;j<n;j++)
			{
				if(op[j])
				{
					int k=(i^(1<<j));
					for(int l=0;l<min(cnt,n-m+1);l++)
					{
						int op=0;
						if(s[cnt]==0)op=1;
						if(a[j+1]<=l)op=1;
//						cout<<a[j]<<' '<<cnt<<' '<<l<<'\n';
						dp[i][l+op]+=dp[k][l];
						dp[i][l+op]%=mod;
					}
				}
			}
//			for(int j=0;j<=n-m;j++)
//			{
//				cout<<dp[i][j]<<' ';
//			}
//			puts("");
		}
		ll ans=0,tt=(1<<n)-1;
		for(int i=0;i<=n-m;i++)
		{
			ans+=dp[tt][i];
			ans%=mod;
		}
		writech(ans,'\n');
	}
	else if(m==n)
	{
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)flag=0;
			if(a[i]==0)flag=0;
		}
		ll ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		if(flag)writech(ans,'\n');
		else puts("0");
	}
	else puts("0");
	return 0;
}


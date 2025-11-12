#include<bits/stdc++.h>
#define ll long long



using namespace std;

const ll M=998244353;

const int N=510;

int n,m;
char ch[N];
int c[N];

int b[N];
int bz[N];

int un=0,ys=0;

int ans=0;

void dfs(int x)
{
	if(x>n)
	{
		if(ys>=m)
		{
			++ans;
			if(ans>=M) ans-=M;
		}
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(bz[i]==0)
		{
			bz[i]=1;
			b[x]=i;
			int t1=un,t2=ys;
			if(c[i]>un&&ch[x]=='1')
			{
				++ys;
			}
			else ++un;
			dfs(x+1);
			bz[i]=0;
			un=t1,ys=t2;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int tp=0;
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i)
	{
		if(ch[i]=='0') tp=1;
	}
	
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		if(c[i]==0) tp=1;
	}
	
	if(m==n)
	{
		if(tp==0)
		{
			ll ss=1;
			for(int i=1;i<=n;++i)
			{
				ss=ss*i%M;
			}
			printf("%lld",ss);
		}
		else printf("0");
	}
	else
	{
		dfs(1);
	}
	printf("%d",ans);
	return 0;
}

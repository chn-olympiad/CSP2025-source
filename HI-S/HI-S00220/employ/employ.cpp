#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define il inline 

const int maxn=505;
const int MOD=998244353;

int n, m, cnt, sum;
int ep[maxn];
char an[maxn];
ll ans=1;
bool b=1;
bool check[maxn];

il int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*f;
}

void dfs(int a,int t)
{
	check[a]=1;
	if(t==n) return;
	if(sum==48)
	{
		ans++;
		return;
	}
	if(t-sum<ep[a]&&an[t]=='1') sum++;
	for(int i=1;i<=n;i++)
	{
		if(!check[i])
		{
			dfs(i,t+1);
			check[i]=0;
			sum--;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin >> an[i];
		if(an[i]=='0') b=0;
	}
	for(int i=1;i<=n;i++)
	{
		ep[i]=read();
		if(ep[i]==0) b=0;
	}
	if(b==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=((ans%MOD)*cnt)%MOD;
			cnt--;
		}
		cout << ans << endl;
		return 0;
	}
	dfs(1,1);
	cout << ans << endl;
	return 0;
}

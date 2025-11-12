#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n,m;
char op[1001];
int c[1001];
int ans;
bool had[1001];
int cur[1001];
int cnt;
void DFS(int len)
{
	if(len==n)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(op[i]=='0'||cnt>=cur[i])
			{
				cnt++;
			}
			//cout<<cur[i]<<" ";
		}
		//cout<<endl;
		ans+=((n-cnt)>=m);
		ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(had[i])
		{
			continue;
		}
		cur[len+1]=c[i];
		had[i]=true;
		DFS(len+1);
		had[i]=false;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>op[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		had[i]=true;
		cur[1]=c[i];
		DFS(1);
		had[i]=false;
	}
	cout<<ans;
	return 0;
}
//I LOVE CCF'S I9
//RUN FASTER PLEASE

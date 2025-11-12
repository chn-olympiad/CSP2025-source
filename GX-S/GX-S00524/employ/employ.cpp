#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
int c[200];
int n,m;
int g;
vector<int>p;
vector<int>st;
int pl=0;
int flag=0;
int flag2=0;
int pi[1000];//c
int inp[1002];
int N=998244353;
int amd;
int ans;
int ap[100];
int check[100];
int last[20];
void go(int x)
{
	int ppp=0;
	memset(last,0,sizeof(last));
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			int fp=0;
			for(int j=1;j<i;j++)
			{
				if(a[j-1]=='0'||last[i]==1)
				{
					fp+=1;
				}
			}
			if(fp>=pi[ap[i]]||a[i-1]=='0')
			{
				//cout<<1<<endl;
				last[i]=1;
			}
			else
			{
				ppp+=1;
			}
		}
		if(ppp>=m)
		{
			//cout<<ppp<<endl;
			ans+=1;
		}
	}
			
	for(int i=1;i<=n;i++)
	{
		if(check[i]==0)
		{
			ap[x]=i;
			check[i]=1;
			go(x+1);
			check[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	inp[1]=1;
	for(int i=2;i<=501;i++)
	{
		inp[i]=inp[i-1]*i;
		inp[i]%=N;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>g;
		pi[i]=g;



		if(g==0)
		{
			flag=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0')
		{
			flag2=1;
		}
	}
	if(flag==0&&flag2==0)
	{

		cout<<inp[n]<<endl;
		return 0;
	}

	else
	{
		go(1);
		cout<<ans<<endl;
	}
	return 0;
}

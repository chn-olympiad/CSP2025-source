#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=501,mod=998244353;
int c[N];
int cnt;
int d[N],e[N],g[N],h[N];
int sum=0;
int mul1=1;
bool f[N];
bool f1[N],f2[N];
int n,m;
int cntqwe;
map<string,bool>mp;
string s;
//bool check() 
//{
//	cout
//	return 1;
//}
//int mul3=0;
//void dfs1(int x)
//{
//	if(x>cntqwe)
//	{
//		mul3++;
//		return;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(f[i]||f2[i]) continue;
//		if(c[i]<h[x]) 
//		{
//			f2[i]=1;
//			dfs1(x+1);
//			f2[i]=0;
//		}
//	}
//}
//void dfs(int x,int qwq,int mul2,int cntqwqqwq)
//{
//	if(x>cnt)
//	{
////		cout<<qwq<<endl;
//		if(qwq>=m)
//		{
////			qwqqq();
////			if(!check())
////			{
////				puts("!!!!!!!!!!!!!");
////			}
//			mul3=0; 
//			dfs1(1);
////			cout<<mul1*mul3<<endl;
//			sum+=mul1*mul3%mod;
//			sum%=mod;	
//		}
//		return;	
//	}
//	int cntqw=0; 
//	for(int i=1;i<=n;i++)
//	{
//		if(f[i])
//		{
//			cntqw++;
//			continue;
//		}
//		if(c[i]>e[x]+cntqwqqwq)
//		{
//			f[i]=1;
//			f1[x]=1;
//			dfs(x+1,qwq+1,mul2,cntqwqqwq);
//			f[i]=0;
//			f1[x]=0;
//			cntqw++;
//		}
//	}
//	if(cntqw!=n)
//	{
//		g[++cntqwe]=x;
//		h[cntqwe]=e[x]+cntqwqqwq;
//		dfs(x+1,qwq,mul2,cntqwqqwq+1);
//		--cntqwe;
//	}
//	
////	f1[x]=0;
//}
void dfs(int x)
{
	if(x>n)
	{
		int qe=0,we=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				we++;
				continue;
			}
			else if(h[i]>we)
			{
				qe++;
			}
			else
			{
				we++;
			}
		}
		if(qe>=m) sum++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			h[x]=c[i];
			dfs(x+1);
			f[i]=0;
			h[x]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==n)
	{
		bool f=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='1')
			{
				f=1;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				f=1;
				break;
			}
		}
		int mul=1;
		for(int i=1;i<=n;i++)
		{
			mul*=i;
			mul%=mod;
		}
		if(!f)
		{
			cout<<mul;	
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	bool f=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			f=1;
			break;
		}
	}
	if(!f)
	{
		int cntqwq=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0) cntqwq++;
		}
		if(n-cntqwq<m)
		{
			cout<<0;
			return 0;
		}
		int mul=1;
		for(int i=1;i<=n;i++)
		{
			mul*=i;
			mul%=mod;
		}
		cout<<mul;
		return 0;
	}
	int cnt1=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1') 
		{
			d[++cnt]=i;
			e[cnt]=cnt1;
		}
		else cnt1++,f1[i+1]=1;
	}
	for(int i=1;i<=cnt1;i++)
	{
		mul1*=i;
		mul1%=mod;
	}
	dfs(1);
	cout<<sum;
	return 0;
} 

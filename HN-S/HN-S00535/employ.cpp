#include <bits/stdc++.h>
#define N 505
#define M 998244353
using namespace std;

int n,m;
long long ans=0;
bool dif[N];
int sta[N],lin[N];
int idk[N];

inline bool check(int k)
{
	int e=0,gav=0;
	for(int i=0;i<k;i++)
	{
		if((!dif[i]) || gav>=lin[i])
		{
			gav++;
			continue;
		}
		e++;
		if(e>=m)
		{
			return true;
		}
	}
	return false;
}

inline void func(int k,bool b)
{
	if(!b && k>=m+idk[k])
	{
		b=check(k);
	}
	if(k>=n)
	{
		if(b)
		{
			ans=(ans+1)%M;
		}
		return;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=sta[i];j>0;j--)
		{
			lin[k]=i;
			sta[i]--;
			func(k+1,b);
			sta[i]++;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	memset(sta,0,n+1);
	memset(lin,0,n);
	memset(idk,0,n);
	for(int i=0;i<n;i++)
	{
		char ch;
		do
		{
			ch=cin.get();
		}while(ch!='0' && ch!='1');
		if(ch=='1')
		{
			dif[i]=true;
		}
		else
		{
			dif[i]=false;
			for(int j=i;j<n;j++)
			{
				idk[j]++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		sta[a]++;
	}
	func(0,false);
	cout<<ans;
	return 0;
}

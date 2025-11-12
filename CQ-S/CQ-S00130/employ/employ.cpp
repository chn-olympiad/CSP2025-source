#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

namespace kanade
{
	int read()
	{
		int ans=0,bs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')bs*=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*bs;
	}
	
	int T[300010],A[300010],P[3000010];
	char S[300010];
	int ans=0;
	int n,m;
	void dfs(int u)
	{
		if(u>n)
		{
			int sum=0,res=0;
			for(int i=1;i<=n;i++)
			{
				if(sum>=A[P[i]]||S[i]=='0')sum++;
				else res++;	
			}
			ans+=(res>=m);
			return ;
		}
		for(int i=1;i<=n;i++)
		{
			if(T[i])continue;
			T[i]=1;
			P[u]=i;
			dfs(u+1);
			P[u]=T[i]=0; 
		}
	}
	
	
	int main()
	{
		n=read(),m=read();
		scanf("%s",S+1);
		for(int i=1;i<=n;i++)
		{
			A[i]=read();
		}
		dfs(1);
		cout<<ans;
		return 0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	kanade::main();
	return 0;
}
/*
炸完了，一年不如一年了qwq 
自己生日打成这个样子也是神人了 
*/

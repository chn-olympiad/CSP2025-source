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
	
	vector<int>vec[4];
	int S[10];
	
	int main()
	{
		int t=read();
		while(t--)
		{
			int n=read();
			for(int j=1;j<=3;j++) 
			{
				vec[j].clear();	
			}
			S[0]=-1;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				S[1]=read(),S[2]=read(),S[3]=read();
				int mx=0,cx=0;
				for(int j=1;j<=3;j++) 
				{
					if(S[j]>S[mx])
					{
						cx=mx;
						mx=j;
					}
					else if(S[j]>S[cx])cx=j;
				}
				ans+=S[mx];
				vec[mx].pb(S[mx]-S[cx]);
			}
			for(int j=1;j<=3;j++) 
			{
				int len=vec[j].size();
				if(len<=n/2)continue;
				sort(vec[j].begin(),vec[j].end());
				int w=0;
				while(len>n/2)
				{
					ans-=vec[j][w];
					w++;
					len--;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	kanade::main();
	return 0;
}
/*
25时，代码部队见 
*/

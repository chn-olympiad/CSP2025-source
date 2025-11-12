//GZ-S00252 毕节东辰实验学校 杜文豪
#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1[2000],s2[2000];
string qu1[2000],qu2[2000];
int vis[2000][2000];
int dfs(int ques,int l,int r)
{
	return 0;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int n=1;n<=a;n++)
	{
		cin>>s1[n]>>s2[n];
	}
	for(int n=1;n<=b;n++)
	{
		cin>>qu1[n]>>qu2[n];
	}
	for(int i=1;i<=b;i++)
	{
		memset(vis,0,sizeof(vis));
		int sum=0;
		for(int n=0;n<sizeof(qu1[n]);n++)
		{
			
			int fla=1;
			int re1=0;int re2=0;
			if(qu1[i][n]!=qu2[i][n] && fla==1)
			{
				re1=n;fla=0;
			}
			if(qu1[i][n]==qu2[i][n] && fla==0)
			{
				re2=n;fla=1;
			}
			if(re1!=0 && re2!=0)
			{
				sum+=dfs(1,re1,re2);
			}
		}
		cout<<sum;
	}
}

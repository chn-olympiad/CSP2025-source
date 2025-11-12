#include<bits/stdc++.h>
//#define int long long

using namespace std;

typedef long long LL;

const int N=200010;

string s1[N],s2[N],t1[N],t2[N];

int work(string t)
{
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='b')
		{
			return i;
		}
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	
	if(m==1)
	{
		for(int k=1;k<=m;k++)
		{
			int res=0;
			
			for(int i=1;i<=n;i++)
			{
				string ans="";
				bool flag=1,flag1=1;
				for(int j=0;j<t1[k].size();j++)
				{
					if(s1[i].size()+j<=t1[k].size())
					{
						string tt=t1[k].substr(j,s1[i].size());
						if(tt==s1[i])
						{
							if(flag1&&ans.size()+s2[i].size()<=t2[k].size()&&ans+s2[i]==t2[k].substr(0,ans.size()+s2[i].size()))ans=ans+s2[i],j+=s2[i].size()-1,flag1=0;
							else ans=ans+t1[k][j];
						}
						else ans=ans+t1[k][j];
					}
					else ans=ans+t1[k][j];
				}
				if(ans!=t2[k])flag=0;
				if(flag)res++;
			}
			printf("%d\n",res);
		}
	}
	else
	{
		for(int k=1;k<=m;k++)
		{
			int res=0;
			int sumt1a=work(t1[k]),sumt1b=t1[k].size()-work(t1[k])-1;
			int sumt2a=work(t2[k]),sumt2b=t2[k].size()-work(t2[k])-1;
			for(int i=1;i<=n;i++)
			{
				bool flag1=0,flag2=0;
				int sums1a=work(s1[i]),sums1b=s1[i].size()-work(s1[i])-1;
				int sums2a=work(s2[i]),sums2b=s2[i].size()-work(s2[i])-1;
				
				if(sumt1a>=sums1a&&sumt1b>=sums1b)
				{
					if(sumt1a-sums1a+sums2a==sumt2a&&sumt1b-sums1b+sums2b==sumt2b)
					{
						res++;
					}
				}
			}
			printf("%d\n",res);
		}
	}
	return 0;
}

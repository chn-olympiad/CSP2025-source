#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
string s1[100010],s2[100010];
string s;
ll sum=0;
void dfs(int ci,string si)
{
	if(ci==n)
	{
		if(si==s)
		{
			sum++;
		}
		return ;
	}
	int bz=0;
	for(int i=0;i<=si.size();i++)
	{
		if(si[i]==s1[ci][1])
		{
			bz=1;
			for(int j=i;j<i+s1[ci].size();j++)
			{
				if(bz==0) break;
				if(si[j]==s1[ci][j])
				{
					bz=1;
				}
				else bz=0;
			}
			if(bz==1)
			{
				dfs(ci+1,si);
				string sis;
				for(int k=0;k<si.size();k++)
				{
					if(k<i) sis[k]=si[k];
					if(k>=i&&k<i+s1.size()-1) sis[k]=s2[ci][k];
					if(k>=i+s1.size()-1) sis[k]=si[k];
				}
				dfs(ci+1,sis);
			}
		}
	}
	dfs(ci+1,si);
}
int main()
{
	freopen("replace.in","r","stdin");
	freopen("replace.out","w","stdout");
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	int sum=0;
	for(int i=1;i<=q;i++)
	{
		cin>>ss>>s;
		dfs(0,ss);
		sum=0;
	}
	return 0;
}


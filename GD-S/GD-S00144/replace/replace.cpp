#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string t1[N],t2[N],s1[N],s2[N];
int ans[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			if(s1[j].size()<t1[i].size()) continue;
			for(int k=0;k<=s1[j].size()-t1[i].size();k++)
			{
				if(s1[j].substr(k,t1[i].size())==t1[i])
				{
					string x=s1[j].substr(0,k),z="";
					if(k+t1[i].size()<=s1[j].size()-1)
					{
						z=s1[j].substr(k+t1[i].size(),s1[j].size()-(k+t1[i].size()));
					}
					string tmp=x+t2[i];
					tmp=tmp+z;
					if(tmp==s2[j])
					{
						ans[j]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}

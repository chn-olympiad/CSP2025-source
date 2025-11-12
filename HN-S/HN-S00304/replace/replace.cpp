#include<bits/stdc++.h>
using namespace std;
long long int n,q,ans;
string s1[200005],s2[200005],t1,t2;
string f(string tt,int a,int b)
{
	for(int i=a;i<a+s1[b].size();i++)
	{
		if(tt[i]!=s1[b][i-a])
		{
			tt="0";
			return tt;
		}
		tt[i]=s2[b][i-a];
	}
	return tt;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int x=1;x<=q;x++)
	{
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		string tt;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				tt=f(t1,i,j);
				if(tt==t2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


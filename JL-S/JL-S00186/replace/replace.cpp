#include <bits/stdc++.h>
using namespace std;
string a[214514],b[214514];
int w[202020][2];
map<string,string>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	bool flag=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]!='a'&&a[i][j]!='b')flag=0;
			if(a[i][j]=='b')sum++;
		}
		if(sum>1)flag=0;
		sum=0;
		for(int j=0;j<b[i].size();j++)
		{
			if(b[i][j]!='a'&&b[i][j]!='b')flag=0;
			if(b[i][j]=='b')sum++;
		}
		if(sum>1)flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<a[i].size();j++)
			{
				if(a[i][j]=='b')w[i][0]=j;
				if(b[i][j]=='b')w[i][1]=j;
			}
		}
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len1=s1.size();
		int len2=s2.size();
		if(len1!=len2)
		{
			cout<<0<<'\n';
			return 0;
		}
		sum=0;
		for(int i=0;i<len1;i++)
		{
			if(s1[i]!='a'&&s1[i]!='b')flag=0;
			if(s1[i]=='b')sum++;
		}
		if(sum>1||sum==0)flag=0;
		sum=0;
		for(int i=0;i<len2;i++)
		{
			if(s2[i]!='a'&&s2[i]!='b')flag=0;
			if(s2[i]=='b')sum++;
		}
		if(sum>1||sum==0)flag=0;
		if(flag)
		{
			int ans=0;
			int wwss1,wwss2;
			for(int i=0;i<len1;i++)if(s1[i]=='b')wwss1=i;
			for(int i=0;i<len2;i++)if(s2[i]=='b')wwss2=i;
			for(int i=1;i<=n;i++)
			{
				if(w[i][0]-w[i][1]==wwss1-wwss2&&a[i].size()-w[i][0]-1<=len1-wwss1-1&&w[i][0]<=wwss1)ans++;
			}
			cout<<ans<<'\n';
		}
		else
		{
			int ans=0;
			for(int l=0;l<len1;l++)
			{
				string t="";
				for(int r=l;r<len2;r++)
				{
					t+=s1[r];
					for(int i=1;i<=n;i++)
					{
						if(t==a[i])
						{
							if(s1.substr(0,l)+b[i]+s1.substr(r+1,len1-r-1)==s2)ans++;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

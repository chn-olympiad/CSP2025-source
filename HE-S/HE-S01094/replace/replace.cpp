#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
string s1[N];
string s2[N];
string t1[N];
string t2[N];
bool chk(string a,string b)
{
	if(a.size()<b.size())
	{
		return false;
	}
	int cnt=0;
	int sit=0;
	for(int i=0;i<a.size();i++)
	{
		if(b[sit]==a[i])
		{
			for(int j=i;j<b.size()+i;j++)
			{
				if(b[sit++]==a[j])
				{
					cnt++;
				}
			}
			if(cnt==b.size())
			{
				return true;
			}else 
			{
				cnt=0;
				sit=0;
			}
		}
	}
	return false;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freoprn("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i];
		cin>>t2[i];
	}
	
	for(int k=1;k<=q;k++)
	{
		int ans=0;
		string ss=t1[k];
		for(int i=1;i<=n;i++)
		{
			if(chk(ss,s1[i]))
			{
				string y=s2[i];
				if(chk(t2[i],y))
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

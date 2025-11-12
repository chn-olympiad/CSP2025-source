#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> mp;
string zu(int x,string a)
{
	string r="";
	int len=a.size();
	for(int i=x;i<len;i++)
	{
		r+=a[i];
	}
	return r;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		mp[t1]=t2;
	}
	while(q--)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		int la=a.size();
		string x="";
		for(int i=0;i<la;i++)
		{
			string y="",z="";
			for(int j=i;j<la;j++)
			{
				y+=a[j];
				z=zu(j+1,a);
				if(x+mp[y]+z==b)
				{
					ans++;
				}
			}
			x+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

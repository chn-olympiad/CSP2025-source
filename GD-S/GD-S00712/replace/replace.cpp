#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string a,b,c,d;
unordered_map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<"0\n";
			continue;
		}
		c="",d="";
		int l=0,r=a.size()-1;
		while(a[l]==b[l]) 
		{
			l++;
		}
		while(a[r]==b[r])
		{
			r--;
		}
		for(int j=l;j<=r;j++)
		{
			c+=a[j];
			d+=b[j];
		}
		if(mp[c]==d)
		{
			ans++; 
		}
		//cout<<c<<' '<<d<<endl;
		for(int j=r+1;j<a.size();j++)
		{
			string u=c,v=d;
			u+=a[j];
			v+=b[j];
			//cout<<u<<' '<<v<<endl;
			if(mp[u]==v)
			{
				ans++;
			}
		}
		for(int j=1;j<=l;j++)
		{
			c=a[l-j]+c;
			d=b[l-j]+d;
			//cout<<c<<' '<<d<<endl; 
			if(mp[c]==d)
			{
				ans++; 
			}
			string u=c,v=d;
			for(int j=r+1;j<a.size();j++)
			{
				u+=a[j];
				v+=a[j];
				//cout<<u<<' '<<v<<endl;
				if(mp[u]==v)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,q,c;
string t,r;
struct asd
{+
	string x;
	string y;
}s[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	cin>>s[i].x>>s[i].y;
	for(int i=0;i<q;i++)
	{
		cin>>t>>r;
		for(int j=0;j<n;j++)
		{
			int u=t.find(s[j].x);
			if(u!=-1)
			{
				string si=s[j].x;
				string e;
				e=t.substr(0,u)+s[j].y+t.substr(u+si.size(),t.size()-u-2*si.size());
				if(e==r)
				c++;
			}	
		} 
		cout<<c<<'\n';
		c=0;
	}
	return 0;
}

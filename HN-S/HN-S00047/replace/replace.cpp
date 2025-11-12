#include <bits/stdc++.h>
using namespace std;
struct r{
	int x,z,l;
}c[200005];
int n,q,x_,z_,l_,ans;
string s,s_;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>s_;
		c[i].l=s.size();
		c[i].x=0;
		while(s[c[i].x]!='b')
			c[i].x++;
		c[i].z=0;
		while(s_[c[i].z]!='b')
			c[i].z++;
	}
	while(q--)
	{
		cin>>s>>s_;
		l_=s.size();
		if(l_!=s_.size())
		{
			cout<<0<<'\n';
			continue;
		}
		x_=0;
		while(s[x_]!='b')
			x_++;
		z_=0;
		while(s_[z_]!='b')
			z_++;
		ans=0;
		for(int i=1;i<=n;i++)
			ans+=((c[i].z-c[i].x==z_-x_)&&(min(c[i].x,c[i].z)<=min(x_,z_))&&(c[i].l-max(c[i].x,c[i].z)<=l_-max(x_,z_)));
		cout<<ans<<'\n';
	}
	return 0;
}

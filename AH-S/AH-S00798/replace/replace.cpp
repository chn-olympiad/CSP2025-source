#include<bits/stdc++.h>
using namespace std;
struct node
{
	string a,b,c;
}p[200005];
int com(string x,string y)
{
	if(y.size()<x.size())
	return 0;
    for(int i=0;i<x.size();i++)
    if(x[i]!=y[i])
    return 0;
    return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b,c,d;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size())
		continue;
		int l=0,r=x.size()-1;
		while(l<=r&&x[l]==y[l])
		l++;
		while(r>=l&&x[r]==y[r])
		r--;
		for(int i=l-1;i>=0;i--)
		a+=x[i];
		for(int i=l;i<=r;i++)
		b+=x[i];
		for(int i=l;i<=r;i++)
		b+=y[i];
		for(int i=r+1;i<x.size();i++)
		c+=y[i];
		p[i].a=a;
		p[i].b=b;
		p[i].c=c;
	}
	while(q--)
	{
		string a,b,c;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		int l=0,r=x.size()-1;
		while(l<=r&&x[l]==y[l])
		l++;
		while(r>=l&&x[r]==y[r])
		r--;
		for(int i=l-1;i>=0;i--)
		a+=x[i];
		for(int i=l;i<=r;i++)
		b+=x[i];
		for(int i=l;i<=r;i++)
		b+=y[i];
		for(int i=r+1;i<x.size();i++)
		c+=y[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		if(b==p[i].b&&com(p[i].c,c)&&com(p[i].a,a))
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}

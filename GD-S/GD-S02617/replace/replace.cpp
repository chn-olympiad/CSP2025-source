#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string w,v;
struct eyz
{
	string a,b;
	int c;
	int d,e;
	int f,g;
}nn[N];
string cc,dd;
int c,d,s;
void do1()
{
	for(int i=1;i<=n;i++)
	{
		cin>>nn[i].a>>nn[i].b;
		nn[i].c=nn[i].a.size();
	}
	for(;q;q--)
	{
		s=0;
		cin>>cc>>dd;
		c=cc.size(),d=dd.size();
		if(c!=d)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<c;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+nn[j].c-1>c)
				{
					continue;
				}
				if((cc.substr(i,nn[j].c)==nn[i].a&&cc.substr(0,i)+nn[j].b+cc.substr(i+nn[j].c)==dd)||(nn[j].b==dd&&nn[j].a==cc))
				{
					s++;
				}
			}
		}
		cout<<s<<"\n";
	}
}
void do2()
{
	for(int i=1;i<=n;i++)
	{
		cin>>w>>v;
		nn[i].d=w.find('b');
		nn[i].e=int(v.find('b'))-int(d);
		nn[i].f=max(w.size()-nn[i].d,v.size()-int(v.find('b')));
	}
	for(;q;q--)
	{
		s=0;
		cin>>cc>>dd;
		c=cc.size(),d=dd.size();
		if(c!=d)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1,f=int(cc.find('b')),g=int(dd.find('b'));i<=n;i++)
		{
			if(f>=nn[i].d&&int(f)-int(g)==nn[i].e&&max(cc.size()-f,dd.size()-int(g))==nn[i].f)
			{
				s++;
			}
		}
		cout<<s<<"\n";
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=1e3)
	{
		do1();
	}
	else
	{
		do2();
	}
	return 0;
 } 

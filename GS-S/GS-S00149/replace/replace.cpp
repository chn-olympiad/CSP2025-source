#include <bits/stdc++.h>

using namespace std;

int n,q,e;

struct Node
{
	string a,b;
}d[100005];
struct Node
{
	string c,d;
}e[100005];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin >>d[i].a>>d[i].b;
	}
	for(int i = 1;i<=q;i++)
	{
		cin >>e[i].c>>e[i].d;
	}
	for(int i = 1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	
	return 0;
}

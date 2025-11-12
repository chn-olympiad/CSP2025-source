#include<bits/stdc++.h>
using namespace std;
struct pa
{
	string a,b;
}p[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
		cin>>p[i].a>>p[i].b;
	}
	string x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}

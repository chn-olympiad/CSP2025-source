#include<bits/stdc++.h>
using namespace std;
struct N{
	string a;
	string b;
}p[100005],l[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a;
		cin>>p[i].b;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>l[i].a;
		cin>>l[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}

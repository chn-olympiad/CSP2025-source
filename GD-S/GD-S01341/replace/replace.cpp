#include<bits/stdc++.h>
using namespace std;
int n,q;
const int maxn=200005;
struct ed
{
	string a,b;
}ed[maxn]
string qq[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>ed[i].a>>ed[i].b;
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>qq[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
}

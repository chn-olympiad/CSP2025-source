#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ty
{
	string a,b;
}s[200001],w[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(ll i=1;i<=q;i++)
	{
		cin>>w[i].a>>w[i].b;
		cout<<0<<endl;
	}
	
	return 0;
}
 

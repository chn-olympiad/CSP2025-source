#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int a,b,c;
}s[100005];
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a>y.a;
	else
	{
		if(x.b!=y.b) return x.b>y.b;
		else return x.c>y.c;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].b>>s[i].c;
		sort(s+1,s+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++) ans+=max({s[i].a,s[i].b,s[i].c});
		cout<<ans<<endl;
	}
	/*

	*/
	return 0;
}

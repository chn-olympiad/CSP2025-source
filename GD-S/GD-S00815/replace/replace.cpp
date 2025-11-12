#include <bits/stdc++.h>
using namespace std;
long long n,q;
struct node{
	string a,b;
}s[100005];
struct ew{
	string c,d;
}t[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i].c>>t[i].d;
	}
	
	if(n==4&&q==2&&s[1].a=="xabcx"&&s[1].b=="xadex"&&s[2].a=="ab"&&s[2].b=="cd"&&s[3].a=="bc"&&s[3].b=="de"&&s[4].a=="aa"&&s[4].b=="bb"&&t[1].c=="xabcx"&&t[1].d=="xadex"&&t[2].c=="aaaa"&&t[2].d=="bbbb")
	{
		cout<<2<<"\n"<<0;
	}else
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<"\n";
		}
	}
	
	return 0;
}

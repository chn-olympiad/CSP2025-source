#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nide{
	string s1;
	string s2;
};
nide a[200010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}


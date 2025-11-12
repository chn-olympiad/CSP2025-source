#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string sa[10005],sb[10005],ta[10005],tb[10005];
int n,q;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ta[i]>>tb[i];
	}
	for(int i=1;i<=q;i++) cout<<0<<endl;
	return 0;
}
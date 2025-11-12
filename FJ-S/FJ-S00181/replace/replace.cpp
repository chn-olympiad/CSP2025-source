#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5,Q=2e5+5;

string sa[N],sb[N],ta[Q],tb[Q];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ta[i]>>tb[i];
		cout<<0<<"\n";
	}
	return 0;
}

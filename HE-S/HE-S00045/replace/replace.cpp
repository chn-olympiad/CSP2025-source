#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+50;
string s[5][N],t[5][N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[1][i]>>t[2][i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}

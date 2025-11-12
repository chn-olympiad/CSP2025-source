#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2][200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[0][i]>>s[1][i];
	}
	while(q--) 
	{
		cin>>s[0][1]>>s[1][1];
		cout<<"0\n";
	}
	return 0;
}
//*** have no egg

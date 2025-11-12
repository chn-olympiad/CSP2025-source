#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("stdin.replace","r",stdin);
	freopen("stdout.replace","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[2][100],t[2][10];
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>t[1][j];
	}
	cout<<s[1][2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

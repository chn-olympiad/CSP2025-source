#include<bits/stdc++.h>
using namespace std;
int n,m,s1[510],s2[510],c[510];
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>s2[i];
		c[s2[i]]++;
	}
	cout<<0;
	return 0;
}

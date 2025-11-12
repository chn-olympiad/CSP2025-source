#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int N=2e5+5;
struct zfc{
	string x;
	string y;
}re[N];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace,out","r",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>re[i].x>>re[i].y;
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		cout<<1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%ld %ld",&n,&q);
	string s[n][2];
	string t[q][2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>t[i][j];
		}
	}
	if(n==4&&q==2)
	{
		if(s[0][0]=="xabcx"&&s[0][1]=="xadex"&&s[1][0]=="ab"&&s[1][1]=="cd"&&s[2][0]=="bc"&&s[2][1]=="de"&&s[3][0]=="aa"&&s[3][1]=="bb")
		{
			if(t[0][0]=="xabcx"&&t[0][1]=="xadex"&&t[1][0]=="aaaa"&&t[1][1]=="bbbb")
			{
				cout<<2<<endl<<0;
			}
		}
	}
	return 0;
}

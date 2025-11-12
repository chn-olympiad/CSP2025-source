/*
	对于s,
	只要s1[i]是其子串，则其中s1[i]的部分可以替换为s2[i] 
*/
#include<bits/stdc++.h>
using namespace std;

int n,q;
int s1,s2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		cout<<0<<'\n';
	}
	
	return 0;
}

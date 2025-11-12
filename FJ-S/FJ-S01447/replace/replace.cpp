#include<bits/stdc++.h>
using namespace std;
int n,q,s;string s1[200001],s2[200001],t1,t2;
void solve(int x,int j)
{
	if(x+s1[j].length()>t1.length())
		return;
	for(int i=0;i<s1[j].length();i++)
		if(t1[x+i]!=s1[j][i])
			return;
	string c="";
	for(int i=0;i<x;i++)
		c=c+t1[i];
	for(int i=0;i<s1[j].length();i++)
		c=c+s2[j][i];
	for(int i=x+s1[j].length();i<t1.length();i++)
		c=c+t1[i];
	if(c==t2)
		s++;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>t1>>t2,s=0;
		for(int i=0;i<t1.length();i++)
			for(int j=1;j<=n;j++)
				solve(i,j);
		cout<<s<<"\n";
	}
	return 0;
}

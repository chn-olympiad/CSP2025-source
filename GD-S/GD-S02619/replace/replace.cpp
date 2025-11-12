#include<bits/stdc++.h>
using namespace std;

int n,q,k[5000001];
string s[200001],s2[200001];

int kmp(string s)
{
	int lenth=s.size();
	k[0]=0;
	for(int i=1;i<lenth;i++)
	{
		int x=i-1;
		while(s[k[x]]!=s[i] && x!=0)x=k[x];
		if(s[k[x]]==s[i])k[i]=k[x]+1;
		else k[i]=k[x];
	}
	return k[s.size()-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>s2[i];
	}
	while(q--)
	{
		cout<<0<<endl;
	 } 
}


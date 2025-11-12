#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,js;
string s[N],s1[N];
string t,t1,tx,ty;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>s1[i];
	while(m--)
	{
		cin>>t>>t1;
		tx="",ty="";
		for(int i=0;i<(int)t.size();i++)
		{
			if(t[i]!=t1[i])
			{
				tx+=t[i];ty+=t1[i];
			}
		}
		js=0;
		for(int i=1;i<=n;i++)
		{
			if(tx.size()>s[i].size())continue;
//			auto x=s[i].find(tx);
//			cout<<x<<'\n';
			if((s[i].find(tx)<s[i].size())&&s1[i].find(ty)<s1[i].size()&&t.find(s[i])<t.size()&&t1.find(s1[i])<t1.size())
				js++;
		}
		cout<<js<<'\n';
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
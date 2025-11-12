#include<bits/stdc++.h>
using namespace std;
string s[200010],t[200010];
map<pair<string,string>,int>mmap;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int flagB=1;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].length();++j)
		{
			if(s[i][j]!='a'&&s[i][j]!='b')
			{
				flagB=0;
			} 
		}
		mmap[make_pair(s[i],t[i])]++;
	}
	if(flagB)
	{
		int poss,post,tong[10000010];
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<s[i].length();++j)
			{
				if(s[i][j]=='b')poss=j;
				if(t[i][j]=='b')post=j;
			}
//			cout<<poss<<" "<<post<<"\n";
			tong[poss-post+5000000]++;
		}
		while(q--)
		{
			string st,ed;
			cin>>st>>ed;
			int spos,tpos;
			for(int j=0;j<st.length();++j)
			{
				if(st[j]=='b')spos=j;
				if(ed[j]=='b')tpos=j;
			}
			cout<<tong[spos-tpos+5000000]<<"\n";
		}
//		cout<<"!\n";
		return 0;
	}
//	if(n>=2000)return 0;
	while(q--)
	{
		string st,ed;
		cin>>st>>ed;
		int len=st.length(),ans=0;
		st=' '+st;
		ed=' '+ed;
		int l,r;
		for(int i=1;i<=len;++i)
		{
			if(st[i]!=ed[i])
			{
				l=i;
				break;
			}
		}
		for(int i=len;i>=1;--i)
		{
			if(st[i]!=ed[i])
			{
				r=i;
				break;
			}
		}
		for(int i=1;i<=l;++i)
		{
			string stlr="",edlr="";
			for(int j=i;j<r;++j)
			{
				stlr+=st[j];
				edlr+=ed[j];
			}
			for(int j=r;j<=len;++j)
			{
				stlr+=st[j];
				edlr+=ed[j];
				ans+=mmap[make_pair(stlr,edlr)];
			}
		}
		cout<<ans<<"\n";
	}
 }


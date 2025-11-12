#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	»ÀΩ‹µÿ¡È
	replace.cpp
*/
const int N = 2e5 + 5, M = 5e6 + 5;
int n,q,trie[M][26],cnt,ans,a[N],b[N];
string s[N][2],t,t1;
vector<int>id[M];
void wbwinsert(string s,int id)
{
	int x=0;
	for(const char&c:s)
	{
		if(!trie[x][c-'a'])
			trie[x][c-'a']=++cnt;
		x=trie[x][c-'a'];
	}
	::id[x].push_back(id);
	return;
}
void wbwquery(int l,int r,int pos,bool f)
{
	int x=0;
	for(int i=l;i<t.size();i++)
	{
		char c=t[i];
		if(!trie[x][c-'a'])
			return;
		x=trie[x][c-'a'];
		if(i>=r)
			for(auto&y:id[x])
			{
				if(f&&b[y]<0&&a[y])
					ans++;
				else if(b[y]-a[y]+1==r-pos+1&&a[y]<=b[y])
					for(int j=a[y];j<=b[y];j++)
					{
						if(t1[l+j]==s[y][1][j])
						{
							if(j==b[y])
								ans++;
							else
								;
						}
						else
							break;
					}
				else
					;
			}
		else
			;
	}
	return;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		wbwinsert(s[i][0],i);
		int l=0,r=s[i][0].size()-1;
		while(l<s[i][0].size()&&s[i][0][l]==s[i][1][l])
			l++;
		while(r>=0&&s[i][0][r]==s[i][1][r])
			r--;
		a[i]=l;
		b[i]=r;
	}
	int tot=0;
	while(q--)
	{
		ans=0;
		cin>>t>>t1;
		int l=0,r=(int)t.size()-1;
		while(l<t.size()&&t[l]==t1[l])
			l++;
		while(r>=0&&t[r]==t1[r])
			r--;
		for(int i=0;i<t.size();i++)
			if(i<=l||r<0)
				wbwquery(i,r,l,r<0);
		cout<<ans<<'\n';
	}
//	cerr<<clock()<<'\n';
	return 0;
}

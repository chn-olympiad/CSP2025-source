#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
string s[N][2];
map<pair<string,string>,bool>mp;
int checkst(string s1,string s2)
{
	string s="\0";
	int st;
	int l=0,r=s1.length();
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(s1.substr(l,mid-l+1)!=s2.substr(l,mid-l+1))
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	st=r;
	return st;
}
int checked(string s1,string s2)
{
	string s="\0";
	int ed;
	int l=0,r=s1.length();
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(s1.substr(mid,r-mid)!=s2.substr(mid,r-mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	ed=l;
	return ed;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	mp[{"\0","\0"}]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1]; 
		mp[{s[i][0],s[i][1]}]=1;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			cout<<'0'<<endl;
			continue;
		}
		string ss="\0";
		int st=checkst(s1,s2);
		if(s1[st-1]!=s2[st-1])
		{
			st--;
		}
		int ed=checked(s1,s2);
		if(s1[ed+1]==s2[ed+1])
		{
			ed++;
		}
		LL ans=0;
		for(int l=0;l<=st;l++)
		{
			for(int r=ed;r<s1.length();r++)
			{
				if(mp[{s1.substr(l,r-l+1),s2.substr(l,r-l+1)}])
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

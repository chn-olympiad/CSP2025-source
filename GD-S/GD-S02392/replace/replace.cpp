#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define il inline
using namespace std;

const int MAXN=1e3+7;

int n,Q,cnt,siz[MAXN],ans,len;
map<string,int> mp;
string to[MAXN][MAXN];

string s,t,s1,s2;

void dfs()
{
//	cout<<s<<endl;
//	if(s==t)
//	{
//		++ans;
//		return ;
//	}
	string now="",pre="",suf="";
	for(int i=0;i<len;i++)
	{
		now="";
		for(int j=i;j<len;j++)
		{
			now+=s[j];
//			cout<<now<<endl;
			if(mp[now])
			{
				pre=suf="";
				for(int k=0;k<i;k++)
					pre+=s[k];
				for(int k=j+1;k<len;k++)
					suf+=s[k];
				for(int k=1;k<=siz[mp[now]];k++)
				{
					s=pre+to[mp[now]][k]+suf;
					if(s==t)
					{
						++ans;
					}
					s=pre+now+suf;
				}
			}
		}
	}
	return ;
}

int main()
{
	fre("replace");
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1;
		cin>>s2;
		if(!mp[s1])
			mp[s1]=++cnt;
		to[mp[s1]][++siz[mp[s1]]]=s2;
	}
	while(Q--)
	{
		ans=0;
		cin>>s;
		cin>>t;
		len=s.length();
		dfs();
		printf("%d\n",ans);
	}
	return 0;
}

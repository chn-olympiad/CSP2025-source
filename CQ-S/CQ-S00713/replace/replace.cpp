#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define endl '\n'

namespace satsujinki{
const int Maxn=5e6+10;
const int maxn=2e5+10;
int n,q;
struct Node{
	int sd;
	int cnt;
	int fail;
	map<int,int>son;
}trie[Maxn];
int fa[Maxn][20];
int sum[Maxn][20];
int cnt;
string s[maxn][2];
string t[2];
queue<int>que;
//set<int>st;

void MAIN()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int now=0;
		for(int j=0;j<(int)s[i][0].size();j++)
		{
			int id=(s[i][0][j]-'a')*26+s[i][1][j]-'a';
			if(!trie[now].son[id])
			{
				cnt++;
				trie[now].son[id]=cnt;
				trie[cnt].sd=trie[now].sd+1;
			}
			now=trie[now].son[id];
		}
		trie[now].cnt++;
	}
	for(pair<int,int>i:trie[0].son)
	{
		que.push(i.second);
	}
	while(que.size())
	{
		int top=que.front();
		que.pop();
		for(pair<int,int>i:trie[top].son)
		{
			int now=trie[top].fail;
			while(now&&!trie[now].son[i.first])
			{
				now=trie[now].fail;
			}
			now=trie[now].son[i.first];
			trie[i.second].fail=now;
			que.push(i.second);
		}
		fa[top][0]=trie[top].fail;
		sum[top][0]=trie[trie[top].fail].cnt;
		for(int j=1;fa[fa[top][j-1]][j-1];j++)
		{
			fa[top][j]=fa[fa[top][j-1]][j-1];
			sum[top][j]=sum[top][j-1]+sum[fa[top][j-1]][j-1];
		}
	}
	while(q--)
	{
		cin>>t[0]>>t[1];
		int minn=1e9,maxx=-1;
		for(int i=0;i<(int)t[0].size();i++)
		{
			if(t[0][i]!=t[1][i])
			{
				minn=min(minn,i);
				maxx=i;
			}
		}
		int now=0,ans=0;
		for(int i=0;i<(int)t[0].size();i++)
		{
			int id=(t[0][i]-'a')*26+t[1][i]-'a';
			while(now&&!trie[now].son[id])
			{
				now=trie[now].fail;
			}
			now=trie[now].son[id];
			if(i>=maxx&&i-trie[now].sd+1<=minn)
			{
				ans+=trie[now].cnt;
				int wz=now;
				for(int j=19;j>=0;j--)
				{
					if(fa[wz][j]&&i-trie[fa[wz][j]].sd+1<=minn)
					{
						ans+=sum[wz][j];
						wz=fa[wz][j];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	satsujinki::MAIN();
//while(1);
	return 0;
}
/*
time:1.0 S
memory:2048 MiB
real:1180MB

这个题目应该就是要建满足两个字符串的当前位置都匹配的AC自动机，然后直接跑答案就行 
*/

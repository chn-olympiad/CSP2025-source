#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+6;
string s[N][2];
struct Node
{
	int son[30];
	int fail;
	vector<int> v;
}tr[M][2];
int trcnt;
void Updata(int i,int j)
{
	int u=0;
	for(int k=0;k<s[i][j].size();k++)
	{
		int& now=tr[u][j].son[s[i][j][k]-'a'+1];
		if(!now)now=++trcnt;
		u=now;
	}
	tr[u][j].v.push_back(i);
}
string t,tt;
int you[200005],youu[200005],tim,deng[M];
int Q()
{
	int u=0,uu=0,ans=0;
	for(int i=0;i<t.size();i++)
	{
		int now=tr[u][0].son[t[i]-'a'+1];
		int noww=tr[uu][1].son[tt[i]-'a'+1];
		u=now;
		uu=noww;
		int cnt1=0,cnt2=0;
		tim++;
		for(int j=u;j;j=tr[j][0].fail)for(auto v:tr[j][0].v)you[v]=tim;
		for(int j=uu;j;j=tr[j][1].fail)
		{
			for(auto v:tr[j][1].v)
			{
				if(you[v]==tim)
				{
					//cout<<v<<" "<<i<<endl;
					if(deng[t.size()]-deng[i+1]==t.size()-i-1&&deng[i+1-s[v][0].size()]==i-s[v][0].size()+1)ans++;
				}
			}
		}
	}
	return ans;
}
queue<int> q;
void build(int j)
{
	for(int i=1;i<=26;i++)
	{
		if(tr[0][j].son[i])q.push(tr[0][j].son[i]);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=26;i++)
		{
			int &v=tr[u][j].son[i];
			if(!v)
			{
				v=tr[tr[u][j].fail][j].son[i];
			}
			else
			{
				tr[v][j].fail=tr[tr[u][j].fail][j].son[i];
				q.push(v);
			}
		}
	}
}
void prin(int u,int f)
{
	for(int i=1;i<=26;i++)
	{
		if(tr[u][f].son[i])
		{
			cout<<u<<" "<<tr[u][f].son[i]<<" "<<char(i+'a'-1)<<endl;
			prin(tr[u][f].son[i],f);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		Updata(i,0);
		//Updata(i,1);
	}
	//prin(0,0);
	//cout<<endl;
	trcnt=0;
	for(int i=1;i<=n;i++)
	{
		Updata(i,1);
	}
	
	//prin(0,1);
	build(0);
	build(1);
	while(q--)
	{
		cin>>t>>tt;
		if(t.size()!=tt.size())
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=t.size();i++)deng[i]=deng[i-1]+(t[i-1]==tt[i-1]);
		//for(int i=1;i<=t.size();i++)cout<<deng[i]<<" ";
		//cout<<endl;
		cout<<Q()<<'\n';
		for(int i=1;i<=t.size();i++)deng[i]=0;
	}
	cout<<endl;
	return 0;
}
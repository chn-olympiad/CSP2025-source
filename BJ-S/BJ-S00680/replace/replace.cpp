#include <bits/stdc++.h>
using namespace std;

const int N=4e5+5;
const int L=2500005;
const int P1=131;
const int P2=12331;
const int Mod=1e9+9;

char s1[L*2], s2[L*2];
pair<unsigned long long,long long> val[N], num[N];
int typ[N], c[L], ans[N], n, q;
string pre[N], suf[N];
vector<int> vec[N];
pair<int,int> ed[N];

void update(int x,int y)
{
	for(int i=x;i<L;i+=i&-i)
		c[i] += y;
}

void clear(int x)
{
	for(int i=x;i<L;i+=i&-i)
		c[i]=0;
}

int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=i&-i)
		ans += c[i];
	return ans;
}

struct Trie
{
	int son[L][26], dfsn[L], sz[L], Indx, IIndx;

	Trie()
	{
		memset(son,0,sizeof(son));
		memset(dfsn,0,sizeof(dfsn));
		Indx=IIndx=0;
	}

	void clear()
	{
		for(int i=0;i<=Indx+1;i++)
		{
			memset(son[i],0,sizeof(son[i]));
			dfsn[i]=sz[i]=0;
		}
		Indx=IIndx=0;
	}

	int Add(string s)
	{
		int n=s.length(), rt=0;
		for(int i=0;i<n;i++)
		{
			if(!son[rt][s[i]-'a'])
				son[rt][s[i]-'a']=++Indx;
			rt=son[rt][s[i]-'a'];
		}
		return rt;
	}

	void dfs(int x)
	{
		dfsn[x]=++IIndx, sz[x]=1;
		for(int i=0;i<26;i++)
			if(son[x][i])
			{
				dfs(son[x][i]);
				sz[x] += sz[son[x][i]];
			}
	}

	int getpoint(string s)
	{
		int n=s.length(), rt=0;
		for(int i=0;i<n;i++)
		{
			rt=son[rt][s[i]-'a'];
			if(!rt)
				return -1;
		}
		return rt;
	}
} Tr1, Tr2;

void work(int id)
{
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int l=1, n=strlen(s1+1), m=strlen(s2+1), r=n;
	if(n!=m)
	{
		val[id]=make_pair(114514,114514);
		return;
	}

	bool notallsame=false;
	for(int i=1;i<=n;i++)
		if(s1[i]!=s2[i])
		{
			notallsame=true;
			l=i;
			break;
		}

	if(!notallsame)
		return;

	while(s1[r]==s2[r])
		r--;

	unsigned long long h1=0;
	long long h2=0;
	for(int i=l;i<=r;i++)
	{
		h1=h1*P1+s1[i];
		h2=(h2*P2+s2[i])%Mod;
	}

	for(int i=l;i<=r;i++)
	{
		h1=h1*P1+s2[i];
		h2=(h2*P2+s1[i])%Mod;
	}

	val[id]=make_pair(h1,h2);
	for(int j=l-1;j>=1;j--)
		pre[id] += s1[j];

	for(int j=r+1;j<=n;j++)
		suf[id] += s1[j];
}

struct Opt
{
	int x,y,op;
} que[1000005];

bool cmp(Opt a,Opt b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.op<b.op;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		work(i);

	for(int i=1;i<=q;i++)
		work(i+n);

	for(int i=1;i<=n+q;i++)
		num[i]=val[i];

	sort(num+1,num+n+q+1);
	int cnt=unique(num+1,num+n+q+1)-num-1;
	for(int i=1;i<=n+q;i++)
		typ[i]=lower_bound(num+1,num+cnt+1,val[i])-num;

	for(int i=1;i<=n+q;i++)
		vec[typ[i]].push_back(i);

	for(int i=1;i<=cnt;i++)
	{
		bool haveupd=false, haveque=false;
		for(auto x:vec[i])
			if(x>n)
				haveque=true;
			else
				haveupd=true;

		if(!haveupd || !haveque)
			continue;

		Tr1.clear(), Tr2.clear();
		for(auto x:vec[i])
			if(x>n)
			{
				ed[x].first=Tr1.Add(pre[x]);
				ed[x].second=Tr2.Add(suf[x]);
			}

		Tr1.dfs(0), Tr2.dfs(0);
		int Cnt=0;
		for(auto x:vec[i])
			if(x>n)
				que[++Cnt]=(Opt){Tr1.dfsn[ed[x].first],Tr2.dfsn[ed[x].second],x};
			else
			{
				int p1=Tr1.getpoint(pre[x]), p2=Tr2.getpoint(suf[x]);
				if(p1!=-1 && p2!=-1)
				{
					int l1=Tr1.dfsn[p1], r1=l1+Tr1.sz[p1]-1, l2=Tr2.dfsn[p2], r2=l2+Tr2.sz[p2]-1;
					que[++Cnt]=(Opt){l1,l2,1};
					que[++Cnt]=(Opt){l1,r2+1,-1};
					que[++Cnt]=(Opt){r1+1,l2,-1};
					que[++Cnt]=(Opt){r1+1,r2+1,1};
				}
			}

		sort(que+1,que+Cnt+1,cmp);

		for(int i=1;i<=Cnt;i++)
			if(que[i].op<=n)
				update(que[i].y,que[i].op);
			else
				ans[que[i].op]=query(que[i].y);

		for(int i=1;i<=Cnt;i++)
			if(que[i].op<=n)
				clear(que[i].y);
	}

	for(int i=n+1;i<=n+q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
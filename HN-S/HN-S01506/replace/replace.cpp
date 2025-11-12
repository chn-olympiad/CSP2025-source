#include<iostream>
#include<queue>
#include<cstring>
#define ULL unsigned long long 
using namespace std;
const int MAXN=2e5,MAXM=5e6;
int Trie[MAXN][30],f[MAXM],ch[MAXM];
int ed[MAXM],fail[MAXM],p,cnt[MAXM];
bool visit[MAXM];
ULL hashm[MAXN],hash[MAXM],hash2[MAXM];
string s1[MAXN],s2[MAXN],S1,S2;
void insert(string s,int edi)
{
	int q=0;
	for(int i=0;i<s.size();i++)
	{
		int nxt=s[i]-'a';
		if(Trie[q][nxt])q=Trie[q][nxt];
		else 
		{
			Trie[q][nxt]=++p;
			f[p]=q;
			ch[p]=s[i];
			q=Trie[q][nxt];
		}
	}
	ed[q]=edi;
	cnt[q]++;
}

struct Node
{
	int ind,len;
};

void BFS()
{
	queue<Node > q;
	q.push({0,0});
	while(!q.empty())
	{
		Node node=q.front();
		q.pop();
		int now=node.ind;
		if(visit[now])continue;
		visit[now]=1;
	//	cout<<node.ind<<' '<<f[node.ind]<<endl;
		for(int i=0;i<27;i++)
		{
			if(Trie[now][i])
			{
				q.push({Trie[now][i],node.len+1});
			}
			
			int j=fail[f[now]];
			if(node.len>1)
			{
				while(!Trie[j][ch[now]-'a']&&j!=0)j=fail[j];
				if(Trie[j][ch[now]-'a'])j=Trie[j][ch[now]-'a'];
				fail[now]=j;
				cnt[now]+=cnt[fail[now]];
				if(!ed[now])ed[now]=ed[fail[now]];
			}
		}
	}
}

void init_hash(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s2[i].size();j++)
		{
			//cout<<hashm[i]<<' ';
			hashm[i]*=131;
			hashm[i]+=s2[i][j]-'a';
		}
	//	cout<<'\n';
	}
}

void i_hash()
{
	for(int i=0;i<=S2.size();i++)
	{
		hash[i]=hash[i-1]*131+S2[i]-'a';
	}
	for(int i=0;i<=S1.size();i++)
	{
		hash2[i]=hash2[i-1]*131+S1[i]-'a';
	}
}

ULL pow(int a,int b)
{
	if(b==0)return 1;
	if(b==1)return a;
	ULL ret=pow(a,b/2);
	ret*=ret;
	if(b%2)ret*=a;
	return ret;
}

ULL calc_hash(int l,int r)
{
//	cout<<l<<' '<<r<<' '<<hash[r]<<' '<<hash[l]<<' '<<pow(131,r-l)<<' '<<hash[r]-(hash[l]*pow(131,r-l))<<'\n';
	if(r<=0)return 0;
	if(l<=0)return hash[r];

	return hash[r]-(hash[l]*pow(131,r-l));
}

ULL calc_hash1(int l,int r)
{
//	cout<<l<<' '<<r<<' '<<hash[r]<<' '<<hash[l]<<' '<<pow(131,r-l)<<' '<<hash[r]-(hash[l]*pow(131,r-l))<<'\n';
	if(r<=0)return 0;
	if(l<=0)return hash2[r];
	
	return hash2[r]-(hash2[l]*pow(131,r-l));
}

void solve()
{
	int ans=0,j=0;
	for(int i=0;i<S1.size();i++)
	{
		while(!Trie[j][S1[i]-'a']&&j>0)j=fail[j];
		if(Trie[j][S1[i]-'a'])j=Trie[j][S1[i]-'a'];
		//cout<<i<<' '<<j<<' '<<ed[j]<<'\n';
		if(cnt[j])
		{
			
		//	cout<<ed[j]<<" "<<hashm[ed[j]]<<'\n';
			if(hashm[ed[j]]==calc_hash(i-s1[ed[j]].size(),i)&&\
			calc_hash(-1,i-s1[ed[j]].size())==calc_hash1(-1,i-s1[ed[j]].size())&&\
			calc_hash(i,s1[ed[j]].size()-1)==calc_hash1(i,s1[ed[j]].size()-1))ans+=cnt[j];
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		insert(s1[i],i);
	}
	init_hash(n);
	BFS();
//	for(int i=0;i<=p;i++)
//	{
//		cout<<(char)ch[i]<<' '<<ed[i]<<' '<<cnt[i]<<' '<<fail[i]<<'\n';
//	}
	for(int i=1;i<=m;i++)
	{
		cin>>S1>>S2;
		i_hash();
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
	


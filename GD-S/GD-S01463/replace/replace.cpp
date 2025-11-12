#include<bits/stdc++.h>

namespace LHY
{

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second
#define debug cerr<<"now is:"<<__FUNCTION__<<" on line "<<__LINE__<<'\n'

using LL = long long;
using LD = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;

/*
'z'+1=='{'

'z' '{' '|' '}'
*/

const int inf=0x3f3f3f3f;

const int M=5200010,V=30;

int n,q,pos[M];

struct Tree_1//Trie,insert,find 
{
	map<int,int> nex[M];
	int c;
	
	int insert(string s)
	{
		int now=0;
		for(auto o:s)
		{
			if(nex[now][o-'a']==0) nex[now][o-'a']=++c;
			now=nex[now][o-'a']; 
		}
		return now;
	}
	
	int find(string s)
	{
		int now=0;
		for(auto o:s)
		{
			if(nex[now][o-'a']==0) return -1;
			now=nex[now][o-'a']; 
		}
		return now;
	}
}T1;


struct Tree_2
{
	/*
	give a pos
	insert
	count
	*/
	int nex[M][V],fail[M];
	LL val[M];
	int c;
	
	void insert(int& rt,string s)
	{
		if(rt==0) rt=++c;
		int now=rt;
		for(auto o:s)
		{
			if(nex[now][o-'a']==0) nex[now][o-'a']=++c;
			now=nex[now][o-'a'];
		}
		++val[now];
//		cerr<<rt<<' '<<s<<' '<<now<<' '<<"add\n";
	}
	
	void build(int& rt)
	{
		if(rt==0) return ;
		queue<int> q;
		q.push(rt);
		fail[rt]=rt;
		while(!q.empty())
		{
			int cu=q.front();
			q.pop();
			
//			if(fail[cu]==0) cerr<<"w------\n";
			
//			cerr<<"build:"<<cu<<' '<<fail[cu]<<'\n';
			
			if(cu!=fail[cu])
			{
				val[cu]+=val[fail[cu]];
			}
			
			rep(i,0,V-1)
			{
				if(nex[cu][i]==0) nex[cu][i]=rt;
			}
			rep(i,0,V-1)
			{
				if(nex[cu][i]==rt)
				{
					nex[cu][i]=nex[fail[cu]][i];
				}
				else
				{
					if(nex[cu][i]!=nex[fail[cu]][i])
					{
						fail[nex[cu][i]]=nex[fail[cu]][i];
					}
					else 
					{
						fail[nex[cu][i]]=rt;
					}
					q.push(nex[cu][i]);
				}
			}
		}
	}
	
	/*
	rem to get answer from fail 
	*/ 
	
	LL count(int& rt,string s)
	{
		if(rt==0) return 0;
		int now=rt;
		LL ans=0;
		for(auto o:s)
		{
			now=nex[now][o-'a'];
			ans+=val[now];
		}
		return ans;
	}
}T2;

/*
struct Tree_3
{
	
	int nex[M][V],fail[M];
	LL val[M];
	int c;
	
	void insert(string s)
	{
		int now=0;
		for(auto o:s)
		{
			if(nex[now][o-'a']==0) nex[now][o-'a']=++c;
			now=nex[now][o-'a'];
		}
		++val[now];
	}
	
	void build()
	{
		queue<int> q;
		q.push(0);
		fail[0]=0;
		
		while(!q.empty())
		{
			int cu=q.front();
			q.pop();
			
			if(cu!=fail[cu])
			{
				val[cu]+=val[fail[cu]];
			}
			
			rep(i,0,V-1)
			{
				if(nex[cu][i]==0)
				{
					nex[cu][i]=nex[fail[cu]][i];
				}
				else
				{
					if(nex[cu][i]!=nex[fail[cu]][i])
					{
						fail[nex[cu][i]]=nex[fail[cu]][i];
					}
					q.push(nex[cu][i]);
				}
			}
		}
	}
	
	
	
	
	
	LL count(string s)
	{
		int now=0;
		LL ans=0;
		for(auto o:s)
		{
			now=nex[now][o-'a'];
			ans+=val[now];
		}
		return ans;
	}
}T3;
*/
//rem to get answer from fail 

void solve()
{
	cin>>n>>q;
	rep(i,1,n)
	{
		string s1,s2;
		cin>>s1>>s2;
		int lth=s1.length();
		int minn=inf,maxn=0;
		bool tag=false;
		rep(i,0,lth-1)
		{
			if(s1[i]!=s2[i])
			{
				tag=true;
				minn=min(minn,i);
				maxn=max(maxn,i);
			}
		}
		if(!tag)
		{
		//TODO	
//			T3.insert(s1);
//			cerr<<s1<<' '<<s2<<'\n';
//			cerr<<"T3:"<<s1<<'\n';
		}
		else
		{
			int id=T1.insert(s1.substr(minn,maxn-minn+1)+"|"+s2.substr(minn,maxn-minn+1));
			string s3;
			rep(i,0,lth-1)
			{
				if(i<minn)
				{
					s3.pb(s1[i]);
				}
				else if(i==minn)
				{
					s3.pb('{');
				}
				else if(i>maxn)
				{
					s3.pb(s1[i]);
				}
			}
			T2.insert(pos[id],s3);
//			cerr<<s1.substr(minn,maxn-minn+1)+"|"+s2.substr(minn,maxn-minn+1)<<' ';
//			cerr<<id<<' '<<s3<<'\n';
		}
	}	
	
	rep(i,0,T1.c)
	{
		T2.build(pos[i]); 
	}
	
	rep(lol,1,q)
	{
		string t1,t2;
		cin>>t1>>t2;
		
		if(t1.length()!=t2.length())
		{
			cout<<0<<'\n';
			continue;
		}
		
		int lth=t1.length();
		int minn=inf,maxn=0;
		bool tag=false;
		rep(i,0,lth-1)
		{
			if(t1[i]!=t2[i])
			{
				tag=true;
				minn=min(minn,i);
				maxn=max(maxn,i);
			}
		}
		
		LL ans=0;
		
		if(tag)
		{
//			cerr<<"q:"<<i<<'\n';
			int id=T1.find(t1.substr(minn,maxn-minn+1)+"|"+t2.substr(minn,maxn-minn+1));
			if(id!=-1)
			{
				string t3;
				rep(i,0,lth-1)
				{
					if(i<minn)
					{
						t3.pb(t1[i]);
					}
					else if(i==minn)
					{
						t3.pb('{');
					}
					else if(i>maxn)
					{
						t3.pb(t1[i]);
					}
				}
				ans+=T2.count(pos[id],t3);
//				cerr<<"t3:"<<t3<<'\n';
			}
			
//			cerr<<t1.substr(minn,maxn-minn+1)+"|"+t2.substr(minn,maxn-minn+1)<<'\n';
		}
		/*
		string t4;
		rep(i,0,lth-1)
		{
			if(t1[i]!=t2[i])
			{
				t4.pb('}');
			}
			else
			{
				t4.pb(t1[i]);
			}
		}
		
		cerr<<t4<<'\n';
		
		if(lol==1)
		{
			cerr<<ans<<'\n';
		}
		
		ans+=T3.count(t4);
		
		if(lol==1) cerr<<t1<<' '<<t2<<' '<<t4<<'\n';
		
		if(lol==1)
		{
			cerr<<ans<<'\n';
		}
		*/
		
		cout<<ans<<'\n';
	}
	
	/*
	ans to open long long!!!!!!!
	*/
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	solve();
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
/*
×¢ÒâÌØÅÐ |T_1| != |T_2|

 
*/

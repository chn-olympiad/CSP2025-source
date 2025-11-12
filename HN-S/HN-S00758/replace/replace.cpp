#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=5e6+5;
unsigned long long base=13331,pw[M],hsh1[M],hsh2[M],S[M],T[M];
void init(int n=M-4)
{
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*base;
}
void makehsh(unsigned long long hsh[],string s)
{
	for(int i=0;i<(int)s.size();i++)
		hsh[i+1]=hsh[i]*base+s[i];
}
unsigned long long gt1(int l,int r)
{
	if(r<l) return 0;
	return hsh1[r]-hsh1[l-1]*pw[r-l+1];
}
unsigned long long gt2(int l,int r)
{
	if(r<l) return 0;
	return hsh2[r]-hsh2[l-1]*pw[r-l+1];
}
unsigned long long calchsh(string s)
{
	unsigned long long hsh=0;
	for(int i=0;i<(int)s.size();i++)
		hsh=hsh*base+s[i];
	return hsh;
}
struct trie{
	struct node{
		unsigned long long hsh; // 此后缀对应的前缀哈希值 
		int len; // 此后缀对应的前缀长度 
		int oth; // 此后缀对应的另外一边的位置 
	};
	int ch[2][N][26],tot1=0,tot2=0; // 儿子们 
	vector<node> d[N]; // 每个节点存储的信息 
	void insert(string s,string t)
	{
		int n=s.size();
		unsigned long long hsh1=0,hsh2=0;
		bool flag=0;int the_len=0;
		int p1=0,p2=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i]||flag)
			{
				flag=1;
				if(!ch[0][p1][s[i]-'a']) ch[0][p1][s[i]-'a']=++tot1;
				if(!ch[1][p2][t[i]-'a']) ch[1][p2][t[i]-'a']=++tot2;
				p1=ch[0][p1][s[i]-'a'],
				p2=ch[1][p2][t[i]-'a'];
			}
			else
			{
				hsh1=hsh1*base+s[i];
				hsh2=hsh2*base+t[i];
				the_len++;
			}
		}
		d[p1].push_back((node){hsh1,the_len,p2});
	}
	int query(string s,string t)
	{
		makehsh(hsh1,s);
		makehsh(hsh2,t);
		int ans=0,n=s.size(),flag=0;
		int p1=0,p2=0,bg=1e7,ed=-1;
		for(int i=0;i<n;i++)
			if(s[i]!=t[i])
				bg=min(bg,i),
				ed=max(ed,i);
//		cout<<bg<<' '<<ed<<'\n';
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i]||flag)
			{
				flag=1;
//				cout<<i<<'\n';
				if(!ch[0][p1][s[i]-'a']||!ch[1][p2][t[i]-'a']) return ans;
				p1=ch[0][p1][s[i]-'a'],
				p2=ch[1][p2][t[i]-'a'];
				if(i>=ed)
				{
					for(int x=0;x<(int)d[p1].size();x++)
					{
						node v=d[p1][x];
//						cout<<i<<' '<<v.hsh<<' '<<gt1(bg-v.len+1,bg)<<'\n';
						if(v.oth==p2)
						{
							if(bg>=v.len&&v.hsh!=gt1(bg-v.len+1,bg)) ans--;
							if(bg<v.len) ans--;
	//						cout<<i<<' '<<v.hsh<<' '<<gt1(bg-v.len+1,bg)<<'\n';
	//						node u=d[1][p2][v.w];
	//						if(u.len&&bg>=u.len&&u.hsh!=gt2(bg-u.len+1,bg)) continue;
							ans++;
	//						cout<<v.hsh<<'\n';
						}
					}
				}
			}
		}
		return ans;
	}
}tr;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	int n,q;
	string a,b;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a==b) continue;
		tr.insert(a,b);
		S[i]=calchsh(a),
		T[i]=calchsh(b);
	}
	while(q--)
	{
		cin>>a>>b;
		if(a.size()!=b.size()) cout<<"0\n";
		else cout<<tr.query(a,b)<<'\n';
//		cout<<"----------------------\n";
	}
	return 0;
}


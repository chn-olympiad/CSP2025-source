#include<bits/stdc++.h>

#define ll unsigned long long

#define mk make_pair
#define fir first
#define sec second

using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=2e5+5,N=5e6+5;

const ll base=1311131,mod1=1e9+7,mod2=147744151;
ll pw1[N],pw2[N];
int n,q;

string a,b;

string g[Maxn],gg[Maxn];
pair<ll,ll>hg[Maxn],hgg[Maxn];

ll id[114][114];


inline ll get(ll x,ll y){
	return (x*mod2+y*mod1+x*x*y*base);
	
}


pair<ll,ll> lsh[Maxn*2];
int tot;

map<pair<ll,ll>,int>root;

inline pair<ll,ll> gethash(int l,int r){
	pair<ll,ll>res=mk(0,0);
	for(int i=l;i<=r;i++){
		ll val=get(a[i]-'a',b[i]-'a');
		res.fir=(res.fir*base+val)%mod1;
		res.sec=(res.sec*base+val)%mod2;
	}return res;
}

struct ACauto{
	int cnt=1;
	struct tree{
		int son[26],fail,val;
	}t[N*5];//////////
	inline void clear(){
		for(int i=0;i<=cnt;i++){
			t[i].fail=t[i].val=0;
			for(int j=0;j<26;j++)t[i].son[j]=0;
		}cnt=1;
	}
	inline void insert(int p,string s){
		int len=s.size()-1;
		for(int i=1;i<=len;i++){
			int ch=s[i]-'a';
			if(!t[p].son[ch])t[p].son[ch]=++cnt;
			p=t[p].son[ch];
		}t[p].val++;
	}
	inline void build(int p){
		queue<int>h;
		for(int i=0;i<26;i++)t[0].son[i]=1;
		t[p].fail=p-1;
		h.push(p);
		while(!h.empty()){
			int u=h.front();h.pop();
			int Fail=t[u].fail;
			for(int i=0;i<26;i++){
				if(t[u].son[i]){
					t[t[u].son[i]].fail=t[Fail].son[i];
					h.push(t[u].son[i]);
				}else t[u].son[i]=t[Fail].son[i];
			}
		}
	}
	inline int query(int p,string s){
		int tpp=p;
		int len=s.size()-1,res=0;
		for(int i=1;i<=len;i++){
			p=t[p].son[s[i]-'a'];
			int u=p;
			while(u>1)res+=t[u].val,u=t[u].fail;
		}return res;
	}
	
}T;


struct Query{
	int id;
	string a;
};

vector<Query>Q[Maxn];

vector<string>G[Maxn];

int ans[Maxn];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	pw1[0]=1;for(int i=1;i<=5e6;i++)pw1[i]=pw1[i-1]*base%mod1;
	pw2[0]=1;for(int i=1;i<=5e6;i++)pw2[i]=pw2[i-1]*base%mod2;
	for(int j=1;j<=n;j++){
		cin>>a;cin>>b;
		a=" "+a;b=" "+b;
		
		int len=a.size()-1,l=len+1,r=0;
		for(int i=1;i<=len;i++)if(a[i]!=b[i]){l=i;break;}
		for(int i=len;i;i--)   if(a[i]!=b[i]){r=i;break;}
		if(l>r)continue;
		pair<ll,ll> tp=gethash(l,r);
		lsh[++tot]=tp;
		g[j]=a;hg[j]=tp;
		root[tp]=1;
	}
	
	sort(lsh+1,lsh+1+tot);
	tot=unique(lsh+1,lsh+1+tot)-lsh-1;
	for(int i=1;i<=tot;i++)root[lsh[i]]=i;
	
	for(int i=1;i<=n;i++)G[root[hg[i]]].push_back(g[i]);
	
	for(int k=1;k<=q;k++){
		cin>>a;cin>>b;
		a=" "+a;b=" "+b;
		int len=a.size()-1;
		if(len!=b.size()-1){ans[k]=0;continue;}
		int l=len+1,r=0;
		for(int i=1;i<=len;i++)if(a[i]!=b[i]){l=i;break;}
		for(int i=len;i;i--)   if(a[i]!=b[i]){r=i;break;}
		if(l>r){ans[k]=0;continue;}
		pair<ll,ll> val=gethash(l,r);
		if(!root[val]){ans[k]=0;continue;}
		Q[root[val]].push_back({k,a});
	}
	
	for(int i=1;i<=tot;i++){
		T.clear();
		for(string it:G[i])T.insert(1,it);
		T.build(1);
		for(Query it:Q[i]){
			ans[it.id]=T.query(1,it.a);
		}
	}
	
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

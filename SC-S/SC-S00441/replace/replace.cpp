#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

string read(){
	string s="";
	char c=getchar();
	while(c<'a'||c>'z')
		c=getchar();
	while(c>='a'&&c<='z'){
		s=s+c;
		c=getchar();
	}
	return s;
}

const int N=2e5+5,V=5e6+5;
const int mod=1e9+9,bse=131;
const int mod2=998244853,bse2=13331;

int n,m;
string a,b;

int t1[V][26],t2[V][26];
int tt[V][26];
map<pii,int>sum[V],nw;
map<int,int>po[V];
int id1,id2,id;
int rt[V];

void insert(string sl,string sr,pii num){
	int p=0;
	for(int i=0;i<(int)sl.size();i++){
		int x=sl[i]-'a';
		if(!t1[p][x])t1[p][x]=++id1;
		p=t1[p][x];
	}
	if(!rt[p])rt[p]=++id2;
	p=rt[p];
	int p1=0,rot=p;
	for(int i=0;i<(int)sr.size();i++){
		int x=sr[i]-'a';
		if(!t2[p][x])t2[p][x]=++id2;
		if(!tt[p1][x])tt[p1][x]=++id;
		po[rot][p1]=p;
		p=t2[p][x];
		p1=tt[p1][x];
	}
	po[rot][p1]=p;
	sum[p][num]++;
}

void build1(int u){
	if(!u)return;
	vector<pair<pii,int>>ve;
	ve.clear();
	for(auto tmp:sum[u]){
		pii x=tmp.fi;int y=tmp.se;
		ve.emplace_back(tmp);
		nw[x]+=y;
	}
	for(int i=0;i<26;i++)
		if(t2[u][i])build1(t2[u][i]);
	for(auto tmp:ve){
		pii x=tmp.fi;
		int y=tmp.se;
		sum[u][x]=nw[x];
		nw[x]-=y;
	}
	ve.clear();
}

void build(int u){
	nw.clear();
	build1(rt[u]);
	for(int i=0;i<26;i++)
		if(t1[u][i])build(t1[u][i]);
}

ll query(string sl,string sr,pii num){
	int u=0;
	for(int i=0;i<(int)sr.size();i++){
		int x=sr[i]-'a';
		if(!tt[u][x])break;
		u=tt[u][x];
	}
	ll res=0;
	int p=0;
	for(int i=0;i<(int)sl.size();i++){
		int x=sl[i]-'a';
		if(!t1[u][x])break;
		res+=sum[po[rt[p]][u]][num];
		p=t1[p][x];
	}
	return res;
}

string sl="",sr="";
pii num;

void init(){
	a="",b="";
	a=read(),b=read();
	if(a==b)return;
	int l=0,r=a.size()-1;
	for(int j=0;j<(int)a.size();j++)
		if(a[j]!=b[j]){
			l=j;
			break;
		}
	for(int j=a.size()-1;j>=0;j--)
		if(a[j]!=b[j]){
			r=j;
			break;
		}
	sl="",sr="";
	for(int j=l-1;j>=0;j--)
		sl=sl+a[j];
	for(int j=r+1;j<(int)a.size();j++)
		sr=sr+a[j];
	num.fi=0,num.se=0;
	for(int i=l;i<=r;i++){
		num.fi=((ll)num.fi*bse+a[i]-'a'+1)%mod;
		num.se=((ll)num.se*bse2+b[i]-'a'+1)%mod2;
	}
}

signed main(){

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		init();
		insert(sl,sr,num);
	}
	build(0);
	
	for(int i=1;i<=m;i++){
		init();
		printf("%lld\n",query(sl,sr,num));
	}

	return 0;
}

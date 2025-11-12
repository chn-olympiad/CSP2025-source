//#define allLL
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 5000006
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define LL long long
#define ULL unsigned LL
#ifdef allLL
#define int LL
const int INF=(1e18);
#else
const int INF=(1e9);
#endif
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fh=1;*/
while(c<'0'||'9'<c){/*if(c=='-'){fh=-1;}*/c=getchar();}
while('/'<c&&c<':'){x=x*10+(c^'0');c=getchar();}/*x*=fh;*/}
template<typename T>void write(T x){
if(x<0){putchar('-');x=-x;}if(x>9){write(x/10);}putchar('0'+(x%10));}
int n,q;
struct nd{
	int cnt;
	int fail;
	int vis;
	int a[28];
	int& operator [] (int x){
		return a[x];
	}
};
struct ACAM{
	int rt;
	vector<nd>sn;
	int newnd(){
		int id=sn.size();
//		cerr<<sn.size()<<":::ldfkgjrlkne\n";
		sn.push_back({0,0,0,{}});
		return id;
	}
	void reset(){
		sn.clear();
		sn.push_back({0,0,0,{}});
		rt=0;
	}
	void ins(char* s){
		int u=rt;
		for(int i=1;s[i];i++){
			if(!sn[u][s[i]-'a']){
//				cout<<(int)s[i]-'a'<<":::";
//				cout<<sn[u][s[i]-'a']<<"->";
				int x=newnd();
//				cout<<x<<',';
				sn[u][s[i]-'a']=x;
//				cout<<sn[u][s[i]-'a']<<endl;
			}
//		cout<<u<<"->"<<sn[u][s[i]-'a']<<endl;
			u=sn[u][s[i]-'a'];
//			cout<<u<<"::::";
//			for(int j=1;j<=i;j++)cout<<s[j];
//			puts("");
		}
		sn[u].cnt++;
	}
	void bfs(){
		queue<int> q;
		q.push(rt);
//		cerr<<"dkshfdkjvbrte\n";
		while(q.size()){
			int u=q.front();
			q.pop();
//			cerr<<u<<"::"<<sn[u].fail<<endl;
			for(int i=0;i<=26;i++){
				if(!sn[u][i]){
					sn[u][i]=sn[sn[u].fail][i];
				}
				else{
					if(u)sn[sn[u][i]].fail=sn[sn[u].fail][i];
					q.push(sn[u][i]);
				}
			}
		}
		
	}
	
	vector<vector<int> >vv;
	void solve(){
		vv.resize(sn.size());
		for(int i=1;i<(int)sn.size();i++)vv[sn[i].fail].push_back(i);
		queue<int>q;
		q.push(rt);
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto v:vv[u]){
				sn[v].cnt+=sn[u].cnt;
				q.push(v);
			}
		}
	}
	int find(char*s){
		int u=rt;
		int sm=0;
		for(int i=1;s[i];i++){
			u=sn[u][s[i]-'a'];
			sm+=sn[u].cnt;
		}
		return sm;
	}
}tr[N];
int tot;
unordered_map<ULL,int>mp;
char s1[M];
char s2[M];
const ULL P=1019;
char ss[M];
#undef int
int main(){
#ifdef allLL
#define int LL
#endif
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);
	read(q);
	for(int ijk=1;ijk<=n;ijk++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int k=strlen(s1+1);
		int l=0,r=0;
		for(int i=1;i<=k;i++)if(s1[i]!=s2[i])r=i;
		for(int i=k;i;i--)if(s1[i]!=s2[i])l=i;
		if(!l||!r)continue;
		ULL h2=r-l+1;
		int sz=0;
		for(int i=l;i<=r;i++)h2=h2*P+s1[i]-'a'+1;
		for(int i=l;i<=r;i++)h2=h2*P+s2[i]-'a'+1;
		for(int i=1;i<l;i++)ss[++sz]=s1[i];
		ss[++sz]='z'+1;
		for(int i=l+1;i<=k;i++)ss[++sz]=s1[i];
		if(!mp[h2]){
			mp[h2]=++tot;
			tr[tot].reset();
		}
		ss[sz+1]=0;
		tr[mp[h2]].ins(ss);
	}
	for(int i=1;i<=n;i++){
		if(tr[i].sn.size()){
			tr[i].bfs();
			tr[i].solve();
		}
	}
	for(int ijk=1;ijk<=q;ijk++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int k=strlen(s1+1);
		int l=0,r=0;
		for(int i=1;i<=k;i++)if(s1[i]!=s2[i])r=i;
		for(int i=k;i;i--)if(s1[i]!=s2[i])l=i;
		if(!l||!r)continue;
		ULL h2=r-l+1;
		int sz=0;
		for(int i=l;i<=r;i++)h2=h2*P+s1[i]-'a'+1;
		for(int i=l;i<=r;i++)h2=h2*P+s2[i]-'a'+1;
		for(int i=1;i<l;i++)ss[++sz]=s1[i];
		ss[++sz]='z'+1;
		for(int i=l+1;i<=k;i++)ss[++sz]=s1[i];
		ss[sz+1]=0;
		if(!mp[h2]){
			puts("0");
			continue;
		}
		write(tr[mp[h2]].find(ss));
		puts("");
	}
//	cerr<<clock()<<endl; 
//	tr.reset();
//	for(int i=1;i<=n;i++){
//		scanf("%s",s+1);
//		tr.ins(s);
//	}
//	tr.bfs();
//	for(int i=1;i<=q;i++){
//		scanf("%s",s+1);
//		cout<<tr.find(s,i)<<endl;
//	}
	
	
	return 0;
#undef int
}
/*
4 2

*/
/*
4 100
abc
ab
bc
ccc
abcd
abccc
abb
acc
bbab
*/

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool Mbe;
typedef long long ll;
const int N=2e5+5;
const int L=5e6+5;
int n,q,m,rt1,rt2,len[N];
bool tag[N];
char s1[L],s2[L],t1[L],t2[L];
int Q[L],hd,tl;
struct ACAM{
	int fail[L],ch[L][26],idx;
	vector<int> id[L];
	ACAM(){idx=0;}
	inline void insert(char *s,int p,int len){
		int rt=0;
		for(int i=1;i<=len;++i){
			int v=s[i]-'a';
			(!ch[rt][v]?(ch[rt][v]=++idx):0);
			rt=ch[rt][v];
		}
		id[rt].emplace_back(p);
	}
	inline void build(){
		hd=1,tl=0;
		for(int i=0;i<26;i++){
			if(!ch[0][i]) continue;
			fail[ch[0][i]]=0;
			Q[++tl]=ch[0][i];
		}
		while(hd<=tl){
			int u=Q[hd++];
			for(int i=0;i<26;++i){
				if(ch[u][i]){
					fail[ch[u][i]]=ch[fail[u]][i];
					Q[++tl]=ch[u][i];
				}
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
};
ACAM T1,T2;
void solve(){
	read(n);read(q);
	for(int i=1;i<=n;++i){
		scanf("%s",s1+1);scanf("%s",s2+1);
		len[i]=strlen(s1+1);
		T1.insert(s1,i,len[i]),T2.insert(s2,i,len[i]);
	}
	T1.build();T2.build();
	for(int Qu=1;Qu<=q;++Qu){
		scanf("%s",t1+1);scanf("%s",t2+1);
		if((m=strlen(t1+1))!=strlen(t2+1)){
			write(0);
			putchar('\n');
			continue;
		}
		int L=0,R=m+1,ans=0;
		while(t1[L+1]==t2[L+1]) ++L;
		while(t1[R-1]==t2[R-1]) --R;
		rt1=0,rt2=0;
		for(int i=1;i<R-1;++i) rt1=T1.ch[rt1][t1[i]-'a'],rt2=T2.ch[rt2][t2[i]-'a'];
		for(int i=R-1;i<=m;i++){
			rt1=T1.ch[rt1][t1[i]-'a'];
			for(int p=rt1;p;p=T1.fail[p])
				for(int k=0;k<T1.id[p].size();k++)
					tag[T1.id[p][k]]=true;
			rt2=T2.ch[rt2][t2[i]-'a'];
			for(int p=rt2;p;p=T2.fail[p])
				for(int k=0;k<T2.id[p].size();k++)
					ans+=(tag[T2.id[p][k]]&&len[T2.id[p][k]]>=i-L); 
			for(int p=rt1;p;p=T1.fail[p])
				for(int k=0;k<T1.id[p].size();k++)
					tag[T1.id[p][k]]=false;		
		}
		write(ans);
		putchar('\n');
	} 
}
bool Med;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int c=1,T=1;
	while(T--) solve();
//	cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB"<<'\n';
	return 0;
}
/*
O(nL)
*/

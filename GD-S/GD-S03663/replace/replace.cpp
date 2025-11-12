#include<bits/stdc++.h>
using namespace std;bool Mbe;
namespace MAOJUN{

typedef unsigned long long LL;
const int N=2e5+5,M=5e6+5,sd=1007;
int n,m,q,as[N];char s[M];
string s1[N],s2[N],t1[N],t2[N];

int dx,tr[M][26],p1[N],p2[N];
map<LL,int>A;vector<int>B[N];
int dc,L[M],R[M];
void dfs(int u){
	L[u]=++dc;for(int i=0;i<26;i++)if(tr[u][i])dfs(tr[u][i]);R[u]=dc;
}
int n1,n2,bt[M];
inline void U(int l,int r,int k){
	for(l--;r>l;r&=r-1)bt[r]+=k;for(;l>r;l&=l-1)bt[l]-=k;
}
inline int Q(int p){
	int x=0;for(;p<=n2;p+=p&-p)x+=bt[p];return x;
}
struct nd{
	int x,l,r,k;nd(int x,int l,int r,int k):x(x),l(l),r(r),k(k){}
	bool operator<(const nd&b)const{return x!=b.x?x<b.x:!k<!b.k;}
};vector<nd>C;
inline void main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s);for(int j=0;s[j];j++)s1[i]+=s[j];
		scanf("%s",s);for(int j=0;s[j];j++)s2[i]+=s[j];
		if(s1[i]==s2[i])continue;
		int z=s1[i].size(),x=0,y=z-1;
		while(s1[i][x]==s2[i][x])x++;
		while(s1[i][y]==s2[i][y])y--;
		LL H=0;
		for(int j=x;j<=y;j++)H=H*sd+s1[i][j];
		for(int j=x;j<=y;j++)H=H*sd+s2[i][j];
		s1[i].clear();s2[i].clear();
		for(int j=x-1;~j;j--)s1[i]+=s[j];
		for(int j=y+1;j<z;j++)s2[i]+=s[j];
		if(A.find(H)==A.end())A[H]=++m;
		B[A[H]].emplace_back(i);
	}
	for(int i=1;i<=q;i++){
		scanf("%s",s);for(int j=0;s[j];j++)t1[i]+=s[j];
		scanf("%s",s);for(int j=0;s[j];j++)t2[i]+=s[j];
		if(t1[i].size()!=t2[i].size())continue;
		int z=t1[i].size(),x=0,y=z-1;
		while(t1[i][x]==t2[i][x])x++;
		while(t1[i][y]==t2[i][y])y--;
		LL H=0;
		for(int j=x;j<=y;j++)H=H*sd+t1[i][j];
		for(int j=x;j<=y;j++)H=H*sd+t2[i][j];
		t1[i].clear();t2[i].clear();
		for(int j=x-1;~j;j--)t1[i]+=s[j];
		for(int j=y+1;j<z;j++)t2[i]+=s[j];
		if(A.find(H)!=A.end())B[A[H]].emplace_back(-i);
	}
	for(int o=1;o<=m;o++){
		for(int i=0;i<=dx;i++)memset(tr[i],0,sizeof*tr);
		dx=2;
		for(int i:B[o])if(i<0){i=-i;
			int p=1,z=t1[i].size();
			for(int j=0,c;j<z;j++){
				c=t1[i][j]-'a';
				if(!tr[p][c])tr[p][c]=++dx;
				p=tr[p][c];
			}
			p1[i]=p;p=2;z=t2[i].size();
			for(int j=0,c;j<z;j++){
				c=t2[i][j]-'a';
				if(!tr[p][c])tr[p][c]=++dx;
				p=tr[p][c];
			}
			p2[i]=p;
		}
		dc=0;dfs(1);n1=dc;
		dc=0;dfs(2);n2=dc;
		C.clear();
		for(int i:B[o])if(i>0){
			int p=1,z=s1[i].size();
			for(int j=0;j<z;j++)p=tr[p][s1[i][j]-'a'];
			int q=2;z=s2[i].size();
			for(int j=0;j<z;j++)q=tr[q][s2[i][j]-'a'];
			if(!p||!q)continue;
			C.emplace_back(L[p],L[q],R[q],1);
			C.emplace_back(R[p]+1,L[q],R[q],-1);
		}else{i=-i;C.emplace_back(L[p1[i]],L[p2[i]],i,0);}
		sort(C.begin(),C.end());
		for(nd u:C){
			int l=u.l,r=u.r,k=u.k;
			if(!k)as[r]=Q(l);else U(l,r,k);
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",as[i]);
}

}bool Med;int main(){
#ifdef IO
	freopen("C/replace3.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	MAOJUN::main();
	return 0;
}
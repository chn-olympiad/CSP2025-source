#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const int base=2333;
const int MAXN=5000005; 
int n,q,tot=1,nxt[MAXN][26];
char s1[MAXN],s2[MAXN]; 
map<ull,int>M;
int elast1[MAXN],elast2[MAXN],cnt1,cnt2;
struct edge{
	int nxt,id;
	ull v; 
}E1[MAXN<<1],E2[MAXN<<1];
inline void add1(int u,ull v){
	cnt1++;
	E1[cnt1].v=v;
	E1[cnt1].nxt=elast1[u];
	elast1[u]=cnt1;
	return; 
} 
inline void add2(int u,ull v,int id){
	cnt2++;
	E2[cnt2].v=v;
	E2[cnt2].id=id; 
	E2[cnt2].nxt=elast2[u];
	elast2[u]=cnt2;
	return; 
} 
int ans[200005]; 
ull G[200005];
int cntG=0;
int C[200005];
void dfs(int u){
	for(int i=elast1[u];i;i=E1[i].nxt){
		C[E1[i].v]++;
	} 
	for(int i=elast2[u];i;i=E2[i].nxt){
		ans[E2[i].id]=ans[E2[i].id]+C[E2[i].v]; 
	}
	for(int j=0;j<26;j++){
		if(nxt[u][j])dfs(nxt[u][j]);
	}
	for(int i=elast1[u];i;i=E1[i].nxt){
		C[E1[i].v]--;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);scanf("%s",s2+1);
		int id=0,Len=strlen(s1+1);
		for(int j=1;j<=Len;j++){
			if(s1[j]!=s2[j])id=j; 
		}
		if(id!=0){
			ull H=0;
			for(int j=id;j>=1;j--){
				H=H*base+(ull)s1[j]*(114514^(int)s1[j]);
				H=H*base+(ull)s2[j]*(114514^(int)s2[j]); 
			}
			if(M.find(H)==M.end()){
				M[H]=0;
				cntG++,G[cntG]=H; 
			}
			int p=1;
			for(int j=id+1;j<=Len;j++){
				if(!nxt[p][(int)s1[j]-'a']){
					tot++;
					nxt[p][(int)s1[j]-'a']=tot; 
				} 
				p=nxt[p][(int)s1[j]-'a'];
			} 
			add1(p,H);
		} 
	}
	sort(G+1,G+cntG+1); 
	int nowcnt=0;
	for(auto &x:M){
		nowcnt++;
		x.second=nowcnt;
	} 
	for(int i=1;i<=tot;i++){
		for(int j=elast1[i];j;j=E1[j].nxt){
			E1[j].v=M[E1[j].v];
		}
	}
	for(int i=1;i<=q;i++){
		int Min=2000000000,Max=-2000000000;
		scanf("%s",s1+1),scanf("%s",s2+1);
		int Len1=strlen(s1+1),Len2=strlen(s2+1);
		if(Len1!=Len2)continue;
		for(int j=1;j<=Len1;j++){
			if(s1[j]!=s2[j])Min=min(Min,j),Max=max(Max,j); 
		}
		int p=1;
		for(int j=Max+1;j<=Len1;j++){
			if(!nxt[p][(int)s1[j]-'a'])break;
			p=nxt[p][(int)s1[j]-'a'];
		} 
		ull H=0;
		for(int j=Max;j>=1;j--){
			H=H*base+(ull)s1[j]*(114514^(int)s1[j]);
			H=H*base+(ull)s2[j]*(114514^(int)s2[j]); 
			if(j<=Min){
				int el=1,er=cntG;
				while(el<er){
					int eMid=(el+er)>>1;
					if(G[eMid]<H)el=eMid+1;
					else er=eMid;
				} 
				int eMid=(el+er)>>1;
				if(G[eMid]==H){
					add2(p,eMid,i); 
				} 
			} 
		} 
	}
	dfs(1);
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	} 
	return 0;
}

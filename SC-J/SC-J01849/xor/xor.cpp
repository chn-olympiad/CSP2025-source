#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

const int N=5e5+10,M=(1<<20)+10;

struct Node{
	int l,r;
	bool operator<(const Node &o)const{
		if(r!=o.r) return r<o.r;
		return l<o.l; 
	}
}a[N<<1];
int cnt;

int n,k;
int s[N];
int pos[M];
int f[N<<1],g[N<<1];

int main(){
	Fre("xor");
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",s+i),s[i]^=s[i-1];
	for(int i=0;i<M;++i) pos[i]=-1;
	for(int i=1;i<=n;++i){
		pos[s[i-1]]=i-1;
		if(pos[s[i]^k]>=0) a[++cnt]={pos[s[i]^k]+1,i};
	}
	for(int i=0;i<M;++i) pos[i]=-1;
	for(int i=n;i;--i){
		pos[s[i]]=i;
		if(pos[s[i-1]^k]>=0) a[++cnt]={i,pos[s[i-1]^k]};
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;++i) g[i]=max(g[i-1],f[i]=g[lower_bound(a+1,a+i,Node{0,a[i].l})-a-1]+1);
	printf("%d\n",g[cnt]);
	
	return 0;
}
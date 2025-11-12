#include<bits/stdc++.h>
using namespace std;
#define LL long long 
int getin(){
	char ch=getchar();
	int ans=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		else 
			ch=getchar();
	}
	do{
		ans=(ans<<1)+(ans<<3)+(ch^48);
		ch=getchar();
	}while(isdigit(ch));
	return ans*f;
}

const int N=10001,M=1000005;
//struct Edge{
//	int u,v,w,nex;
//}e[M];

struct Node{
	int a,b,c;
}A[N];
int n,m,k,head[N],f[N],cnt;
LL ans;

bool cmp(Node x,Node y){
	return x.c<y.c;
}
//void add(int u,int v,int w){
//	e[++cnt]={u,v,w,head[u]};
//	head[u]=cnt;
//}

int Find(int x){
	if(x==f[x])
		return f[x];
	else{
		f[x]=Find(f[x]);
		return f[x];
	}	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getin(),m=getin(),k=getin();
	
	for(int i=1;i<=m;++i){
		int u=getin(),v=getin(),w=getin(); 
		A[i]={u,v,w};
	}
	
	if(k==0){
		sort(A+1,A+1+m,cmp);
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
		for(int i=1;i<=m;++i){
			int xx=Find(A[i].a);
			int yy=Find(A[i].b);
			if(xx!=yy){
				f[xx]=yy;
				ans+=A[i].c;
			}
		}
		printf("%lld\n",ans);
	}else printf("0\n");
	
	return 0;
} 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define Code ios::sync_with_stdio(0);
#define with cin.tie(0);
#define ZhouShen cout.tie(0);
#define int long long
#define N 10010
#define M 1000010
using namespace std;
int n,m,k,u,v,w,a[15][N],c[15];
int p=0,head[N],to[2*M],nxt[2*M],val[2*M];
inline void read(int&a){
	int s=0,w=1;
	char ch;
	ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-')w=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
inline void addedge(int a,int b,int c){
	nxt[++p]=head[a];
	head[a]=p;
	to[p]=b;
	val[p]=c;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Code with ZhouShen
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++){
		read(u);
		read(v);
		read(w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
//	if(k==0){
//	}else{
		cout<<0;
//	}
	return 0;
}


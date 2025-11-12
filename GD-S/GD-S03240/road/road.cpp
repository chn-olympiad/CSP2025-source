#include <bits/stdc++.h>
using namespace std;

const int M=2e6+100,N=1e5;
const int inf = 2e9+10;

struct edge{
	int d,u,id;
};
class dui{
	static const int DN=M;
	edge l[DN];
	int tp;
	void up(int i){
		for(;i>1;i>>=1){
			if(l[i>>1].d < l[i].d) return;
			swap(l[i>>1],l[i]);
		}
	}
	void down(int i){
		for(int k=i<<1;k<=tp;){
			if(k+1<=tp && l[k+1].d < l[k].d) k+=1;
			if(l[i].d < l[k].d) return;
			swap(l[i],l[k]);
			i=k;
			k<<=1;
		}
	}
public:
	dui():tp(0){
		memset(l,0,sizeof(l));
	}
	void push(int data , int u  ,int id){
		++tp;
		l[tp].d = data;
		l[tp].u = u;
		l[tp].id = id;
		up(tp);
	}
	void pop(){
		swap(l[1],l[tp]);
		tp--;
		down(1);
	}
	edge top(){
		return l[1];
	}
	int size(){
		return tp;
	}
}dd;

int nxt[M],hd[M],tto[M],cst[M],ttl=0;
bool ins[M];
int adde(int u,int v,int c){
	cst[++ttl] = c;
	tto[ttl] = v;
	nxt[ttl] = hd[u];
	hd[u] = ttl;
	return ttl;
}

int fa[N];
int lk(int s,int f){
	if(s == f) return f;
	return fa[s] = lk(f,fa[f]);
}
void hb(int a,int b){
	lk(a,fa[a]);
	lk(fa[a],b);
}
bool ffa(int l,int r){
	lk(l,fa[l]);
	lk(r,fa[r]);
	return fa[l] == fa[r];
}


long long mn=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

//{
//	for(int i=1;i<=1000;i++){
//		fa[i]=i;
//	}
//	lk(2,3);
//	lk(3,4);
//	lk(4,5);
//	lk(6,7);
//	lk(7,5);
//	printf("1 5=%d\n",ffa(1,5));
//	lk(1,2);
//	printf("1 5=%d\n",ffa(1,5));
//	printf("1 6=%d\n",ffa(1,6));
//	return 0;
//}	
	memset(ins,0,sizeof(ins));

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}


//	int mn=inf,mi=0;
	for(int i=0,u,v,c;i<m;i++){
		scanf("%d%d%d",&u,&v,&c);
		dd.push(c,u,adde(u,v,c));
//		if(c<mn){
//			mn=c;
//			mi=u;
//		}
	}
	
	for(;dd.size()>0;){	
		edge t=dd.top();
		int id=t.id ,u=t.u ,v=tto[id] ,c=t.d;dd.pop();
		if(ffa(u,v)) continue;
		ins[id] = 1;
		mn += c;
		hb(u,v);
	}
	for(int i=0,cj,j;i<k;i++){
		scanf("%d",&cj);
		for(int i=1;i<=n;i++){
			scanf("%d",&j);
		}
	}
	cout<<0;
	
	
	return 0;
}

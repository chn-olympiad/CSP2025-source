#include <bits/stdc++.h>
#define debug(x) printf("In Function %s,Line %d,%s:%d.\n",__FUNCTION__,__LINE__,#x,x)
#define cputime printf("CPU used time:%.3lf.\n",(double) clock() / CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);a++)
#define low(a,b,c) for(a=(b);a>=(c);a++)
using namespace std;
typedef unsigned long long var;

template <typename T> inline void read(T &x){
	static char ch;
	static int y;
	x = 0;
	y = 1;
	ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			y = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	x *= y;
}

const int N=1e5+5,M=3e6+5;
var n,m,k,cost[N],sizes,tot,ad,fa[N],ans;
struct node{
	var u,v,w;
};
node edge[M];
bool in[N];

bool cmp(const node &x,const node &y){
	return x.w < y.w;
}
void add(var x,var y,var z){
	edge[++tot].u = x;
	edge[tot].v = y;
	edge[tot].w = z;
}
var find(var x){
	return (fa[x] == x)?(x):(fa[x] = find(fa[x]));
}
void merge(var x,var y){
	x = find(x);
	y = find(y);
	fa[x] = y;
}
var mintree(){
	var i,num,res,f1,f2;
	num = 0;
	res = 0;
	upp(i,1,n+k){
		fa[i] = i;
	}
	//debug(num);
	upp(i,1,tot){
		if(num >= sizes) return res;
		if(in[edge[i].u] || in[edge[i].v]) continue;
		f1 = find(edge[i].u);
		f2 = find(edge[i].v);
		if(f1 != f2){
			///debug(edge[i].u);
			//debug(edge[i].v);
			//debug(edge[i].w);
			res += edge[i].w;
			num++;
			merge(f1,f2);
		}
	}
	return res;
}
void code(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	var i,j,x,y,z,state,num;
	upp(i,1,m){
		read(x);
		read(y);
		read(z);
		add(x,y,z);
		add(y,x,z);
	}
	upp(i,1,k){
		read(z);
		cost[n + i] = z;
		upp(j,1,n){
			read(z);
			add(n+i,j,z);
			add(j,n+i,z);
		}
	}
	sort(edge + 1,edge + 1 + tot,cmp);
	state = 1;
	//debug(tot);
	upp(i,1,k) state *= 2;
	upp(i,0,(state - 1)){
		ad = 0;
		sizes = n;
		upp(j,1,k){
			if(i & (j)){
				in[n+j] = 0;
				sizes++;
				ad += cost[n+j];
			}
			else{
				in[n+j] = 1;
			}
		}
		num = mintree();
		if(ans == 0) ans = num + ad;
		else ans = min(ans,num + ad);
	}
	printf("%lld\n",ans);
}
int main(){
	code();
	return 0;
}
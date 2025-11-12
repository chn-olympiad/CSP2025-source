#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define pint pair<int,int>
#define fst first
#define snd second
#define int long long

int in(){
	char a=getchar();
	int k=0,kk=1;
	while(!isdigit(a)){
		if(a=='-') kk=-1;
		a=getchar();
	}
	while(isdigit(a)){
		k=k*10+a-'0',a=getchar();
	}
	return k*kk;
}
void out(int a){
	if(a < 0) putchar('-'),a=-a;
	if(a > 9) out(a/10);
	putchar('0'+a%10);
}
const int N = 105;
int n,m,tot;
struct node{
	int x,id;
}s[N];
bool cmp(node a,node b){
	return a.x > b.x;
}
void dfs(int x, int y, int cnt, int pd){
	if(cnt == 0){
		out(y), putchar(' '), out(x);
		exit(0);
	}
	if(pd == 1){
		if(x != n) dfs(x+1,y,cnt-1,pd);
		else dfs(x,y+1,cnt-1,!pd);
	}else{
		if(x != 1) dfs(x-1,y,cnt-1,pd);
		else dfs(x,y+1,cnt-1,!pd);
	}
} 
signed main(){
	FRR("seat.in");
	FRW("seat.out");
	n = in(), m = in();
	_rep(i,1,n*m) s[++tot].id=i,s[tot].x=in();
	sort(s+1,s+1+n*m,cmp);
	int k = 1;
	for(int i=1;i<=n*m;++i){
		if(s[i].id == 1){
			k = i;
			break;
		}
	}
	dfs(1,1,k-1,1);
	return 0;
}

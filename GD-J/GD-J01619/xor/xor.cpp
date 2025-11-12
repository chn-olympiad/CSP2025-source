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
const int N = 5e5 + 5;
map <int,int> m;
int n,k,a[N],pr[N],tot,tot1;
struct node{
	int l,r;
}s[N];
bool cmp(node a,node b){
	if(a.l == b.l) return a.r < b.r;
	else return a.l < b.l;
}
#define lc p<<1
#define rc p<<1|1
int L[N],f[N];
struct node1{
	int l,r,maxn;
}tr[N*4];
#define push_up(p) tr[p].maxn = max(tr[lc].maxn,tr[rc].maxn)
void build(int p,int l,int r){
	tr[p].l = l, tr[p].r = r; 
	if(l == r){
		return;
	}
	int m = (l + r) >> 1;
	build(lc,l,m), build(rc,m+1,r);
}
int query(int p,int l,int r){
	if(l<=tr[p].l && r>=tr[p].r){
		return tr[p].maxn;
	}
	int m = (tr[p].l + tr[p].r) >> 1, ans = 0;
	if(l <= m) ans = query(lc,l,r);
	if(r > m) ans = max(ans,query(rc,l,r));
	return ans;
}
void change(int p,int l,int r,int k){
	if(l<=tr[p].l&&r>=tr[p].r){
		tr[p].maxn = k;
		return;
	}
	int m = (tr[p].l + tr[p].r) >> 1;
	if(l <= m) change(lc,l,r,k);
	if(r > m) change(rc,l,r,k);
	push_up(p); 
}

signed main(){
	FRR("xor.in");
	FRW("xor.out");
	n = in(), k = in();
	_rep(i,1,n) a[i] = in();
	pr[1] = a[1];
	_rep(i,2,n) pr[i] = pr[i-1] ^ a[i];
	_rep(i,1,n){
		int tmp = k ^ pr[i];
		if(m[tmp] != 0){
			s[++tot].l = m[tmp]+1, s[tot].r = i;
		}else if(m[tmp] == 0 && tmp == 0){
			s[++tot].l = 1, s[tot].r = i;
		}
		m[pr[i]] = i;
	}
	sort(s+1,s+1+tot,cmp);
	for(int i=1;i<=tot;++i){
		s[++tot1].l = s[i].l, s[tot1].r = s[i].r;
		while(i<tot&&s[i+1].l == s[i].l) ++i;
	}
	for(int i=1;i<=tot1;++i){
		L[s[i].r] = s[i].l;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		f[i] = query(1,1,i);
		if(L[i] != 0){
			f[i] = max(f[i],query(1,1,L[i]-1)+1);
		}
		change(1,i,i,f[i]);
	}
	cout << f[n] << endl;
	return 0;
}

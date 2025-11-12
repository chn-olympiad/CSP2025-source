#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pint pair<int,int>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define fst first
#define snd second
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define pb push_back

int in(){
	char a = getchar();
	int k = 0, kk = 1;
	while(!isdigit(a)){
		if(a == '-') kk = -1;
		a = getchar();
	}
	while(isdigit(a)){
		k = k * 10 + a - '0', a = getchar();
	}
	return k*kk;
}
void out(int a){
	if(a < 0) putchar('-'),a=-a;
	if(a > 9) out(a/10);
	putchar('0'+a%10);
}
const int N = 1e4 + 5, M = 1e6 + 5;
int fa[N],n,m,k;
int find(int a){
	return fa[a]==a?a:fa[a]=find(fa[a]);
}
void bing(int a,int b){
	fa[find(a)] = find(b);
}

struct node{
	int u,v,w;
}s[M];
bool cmp(node a,node b){
	return a.w < b.w;
}

void work1(){
	_rep(i,1,m){
		s[i].u = in(), s[i].v = in(), s[i].w = in();
	}
	_rep(i,1,n) fa[i] = i;
	sort(s+1,s+1+m,cmp);
	int ans = 0, cnt = 0;
	_rep(i,1,m){
		if(find(s[i].u)!=find(s[i].v)){
			bing(s[i].u,s[i].v);
			ans += s[i].w;
			cnt++; 
		}
		if(cnt == n - 1) break;
	}
	cout << ans << "\n";
}
int a[15][N],f[1005][1005];
void work2(){
	memset(f,-1,sizeof(f)); // 
	_rep(i,1,n) fa[i] = i;
	vector <node> s1;
	_rep(i,1,m){
		s1.pb((node){in(),in(),in()});
	}
	_rep(i,1,k){
		a[i][0] = in();
		_rep(j,1,n) a[i][j] = in();
	}
	_rep(i,1,k){
		_rep(j,1,n){
			_rep(k,j+1,n){
				if(f[j][k] == -1) f[j][k] = a[i][j]+a[i][k];
				else f[j][k] = min(f[j][k],a[i][j]+a[i][k]);
//				s1.pb(node{j,k,a[i][j]+a[i][k]});
			}
		}
	}
	_rep(j,1,n){
		_rep(k,1,n){
			if(f[j][k]!=-1) s1.pb((node){j,k,f[j][k]});
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	int ans = 0, cnt = 0;
	for(auto i:s1){
		int u = i.u, v = i.v, w= i.w;
		if(find(u)!=find(v)){
			bing(u,v);
			ans += w;
			cnt++;
		}
		if(cnt == n - 1) break;
	}
	out(ans), putchar('\n');
}

signed main(){
	FRR("road.in");
	FRW("road.out");
//	FRR("in.txt");
//	FRW("mine.txt");
	n = in(), m = in(), k = in();
	if(k == 0){
		work1();
		return 0;
	}
	work2();
	return 0;
	/*
	4 3 1
	1 2 7
	1 3 8
	3 4 9
	0 0 0 111 111
	*/
}


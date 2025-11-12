#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define Rep(i,a,b) for(int i = (a);i >= (b);--i)

using ll = long long;

const int N = 2e5 + 5,K = 2.5e6 + 5;
const ll mod = 1e9 + 9;

int n,q,c,I[N],P[N],T[K][26],C,in[K],out[K],tot;
map<tuple<int,int,int>,int> M;
vector<int> IN[N],OUT[N];
char a[K * 2],b[K * 2];

void ins(int k,char *s){
//	printf("ins %s\n",s);
	int p = 0;
	for(int i = 0;s[i];++i){
		int j = s[i] - 'a';
		if(!T[p][j]) T[p][j] = ++C;
		p = T[p][j];
	}
	P[k] = p;
}

int qry(char *s){
	int p = 0;
	for(int i = 0;s[i];++i){
		int j = s[i] - 'a';
		if(T[p][j]) p = T[p][j]; else break;
	}
	return in[p];
}

void dfs(int u){
	in[u] = ++tot;
	rep(j,0,25) if(T[u][j]) dfs(T[u][j]);
	out[u] = tot;
}

int main(){
//	return system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	rep(j,1,n){
		scanf("%s%s",a + 1,b + 1);
		int m = strlen(a + 1),L = 0,R = 0;
		rep(i,1,m) if(a[i] != b[i]){
			R = i;
			if(!L) L = i;
		}
		ll A = 0,B = 0,E = 0;
		Rep(i,L - 1,1) A = (A + a[i] - 'a' + 1) * 29 % mod;
		Rep(i,R,L)
			B = (B + a[i] - 'a' + 1) * 29 % mod,
			E = (E + b[i] - 'a' + 1) * 29 % mod;
		if(!M.count(make_tuple(A,B,E))) M[make_tuple(A,B,E)] = ++c;
		I[j] = M[make_tuple(A,B,E)],ins(j,a + R + 1);
//		printf("%lld %lld %lld\n",A,B,E);
	}
	dfs(0);
	rep(j,1,n) IN[I[j]].push_back(in[P[j]]),OUT[I[j]].push_back(out[P[j]]);
	rep(i,1,c) sort(IN[i].begin(),IN[i].end()),sort(OUT[i].begin(),OUT[i].end());
	rep(k,1,q){
		scanf("%s%s",a + 1,b + 1);
		int m = strlen(a + 1),m2 = strlen(b + 1),L = 0,R = 0;
		if(m != m2){ puts("0"); continue; }
		rep(i,1,m) if(a[i] != b[i]){
			R = i;
			if(!L) L = i;
		}
		ll A = 0,B = 0,E = 0,ans = 0;
		int Q = qry(a + R + 1);
		Rep(i,R,L)
			B = (B + a[i] - 'a' + 1) * 29 % mod,
			E = (E + b[i] - 'a' + 1) * 29 % mod;
		Rep(i,L,1){
			if(i < L) A = (A + a[i] - 'a' + 1) * 29 % mod;//printf("add %c\n",a[i]);
			if(M.count(make_tuple(A,B,E))){
//		printf("# %lld %lld %lld\n",A,B,E);
				int I = M[make_tuple(A,B,E)];
//				printf("# Q=%d | %d\n",Q,IN[I].size());
//				printf("in:");for(int x : IN[I])printf("%d ",x);puts("");
//				printf("out:");for(int x : OUT[I])printf("%d ",x);puts("");
				ans += IN[I].size();
				ans -= IN[I].end() - upper_bound(IN[I].begin(),IN[I].end(),Q);
				ans -= lower_bound(OUT[I].begin(),OUT[I].end(),Q) - OUT[I].begin();
//				printf("### %lld\n",ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

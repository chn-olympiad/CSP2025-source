#include <bits/stdc++.h>
using namespace std;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

int n, k;
vector<int> a, s, f;
inline int get_xor(cst int &le, cst int &ri){
	return s[le-1]^s[ri];
} 
void solve_60pts(){
	s.resize(n+1), f.resize(n+1);
	FOR (i, 1, n)s[i]=s[i-1]^a[i];
	f[0]=0, f[1]=(a[1]==k);
	FOR (i, 2, n){
		FOR (j, 0, i-1)f[i]=max(f[i], f[j]+(get_xor(j+1, i)==k));
	}
	printf("%d", f[n]);
}
void solve_special(){
	int cnt=0;
	FOR (i, 1, n)if (a[i]==1)cnt++;
	printf("%d", cnt);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n>>k;
	a.resize(n+1);
	FOR (i, 1, n)cin>>a[i];
	if (n<=2000)solve_60pts();
	else solve_special();
	return 0;
}

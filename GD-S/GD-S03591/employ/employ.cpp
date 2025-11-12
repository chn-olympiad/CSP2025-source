#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define pii pair<int,ll>
const int N = 1e4+3, MOD = 998244353;
ll pai = 1;
int n, m,a[505],c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	FOR(i,2,n)
		pai = (pai*i)%MOD;
	cin >> s;
	FOR(i,0,s.length()-1){
		a[i+1] = s[i]-'0';
	}
	FOR(i,1,n){
		cin >> c[i];
	} 
	return 0;
}

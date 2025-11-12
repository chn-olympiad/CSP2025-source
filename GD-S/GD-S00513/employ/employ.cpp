#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int maxn=502,mod=998244353;
int n,m,c[maxn],ans;
int pos[maxn];
bool pas[maxn];
string s,s1;
void solve1(){
	long long res=1;
	for(register int i=1; i<=n; i++)
		res=res*i%mod;
	cout << res << endl;
}
void dfs(int dep){
	if(dep>n){
		int cnt=0;
		for(register int i=1; i<=n; i++){
			if(!pas[i]||cnt>=c[pos[i]]) cnt++;
		}
		if(n-cnt>=m) ans++;
		return;
	}
	for(register int i=1; i<=n; i++){
		if(!pos[i]){
			pos[i]=dep;
			dfs(dep+1);
			pos[i]=0;
		}
	}
}
void solve2(){
	dfs(1);
	cout << ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(register int i=0; i<n; i++){
		pas[i+1]=s[i]-'0';
		s1+="1";
	}
	for(register int i=1; i<=n; i++)
		cin >> c[i];
	if(n<=20) solve2();
	else solve1();
	return 0;
} 

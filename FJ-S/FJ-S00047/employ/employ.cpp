#include <bits/stdc++.h>
#define MAXN 1001
#define MOD 998244353
using namespace std;
int n,m,c[MAXN],id[MAXN];
string s;
void solve1(){//force
	int ans=0,np=0,nc=0;//pass;not pass
	do{
		np=0,nc=0;
		for (int i=1;i<=n;i++) {
			if (nc>=c[id[i]]) {
				nc++;
				continue;	
			}
			if (s[i]=='1') np++;
			else nc++;
		}
		if (np>=m) {
			ans++;
		}
	}while(next_permutation(id+1,id+1+n));
	cout << ans;
}
void solve2() {//m==n
	long long ans=1LL;
	for (int i=1;i<=n;i++) {
		if (s[i]=='0'||c[i]==0) {
			cout << 0;
			return ;
		}
		ans=(ans*i)%MOD;
	}
	cout << ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s=" "+s;
	for (int i=1;i<=n;i++) {
		cin >> c[i];
		id[i]=i;	
	}
	if (n<=10) solve1();
	else if (m==n)solve2();
	else {
		int tot=0;
		for (int i=1;i<=n;i++) if (s[i]=='1') tot++;
		if (m>tot) cout<<0;
		else {
			long long ans=1LL;
			for (int i=1;i<=n;i++) ans=(ans*i)%MOD;
			cout << ans;
		}
	}
	return 0;
}

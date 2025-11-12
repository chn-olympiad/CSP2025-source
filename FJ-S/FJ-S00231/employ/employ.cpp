#include <iostream>
using namespace std;

const int MOD=998244353;
int n,m;
int cnt;
int ans=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int sss;string s;
	for (int i=1;i<=n;++i) cin >> s;
	for (int i=1;i<=n;++i){
		cin >> sss;
		if (sss!=0) ++cnt;
	} for (int i=cnt;i>=cnt;--i){
		ans=(1LL*ans*i)%MOD;
	} cout << ans;
	return 0;
}

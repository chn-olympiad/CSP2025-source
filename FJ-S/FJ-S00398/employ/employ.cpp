#include <bits/stdc++.h>
using namespace std;
int n,m,c[1000];
long long mo=998244353,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i=0;i<n;i++) cin >> c[i];
	bool flag=true;
	for (int i=0;i<n;i++) flag=flag&&s[i]=='1';
	if(flag){
		ans=1;
		for (int i=2;i<=n;i++) ans=(ans*i)%mo;
		cout << ans;
		return 0;
	}
	return 0;
}

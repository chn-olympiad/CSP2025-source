#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,Mod=998244353;
long long n,m;
long long tot;
string s;
long long a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (long long i=1;i<=n;i++){
		cin >> a[i];
		tot*=n;
		tot%=Mod;
	}
	int flag=1;
	for (long long i=0;i<s.length();i++){
		if (s[i]=='1') {
			flag=0;
			break;
		}
	}
	if (flag) cout << 0;
	else cout << tot;
	return 0;
}



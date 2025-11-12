#include<bits/stdc++.h>
using namespace std;
const int MAXN=510,MOD=998244353;
int c[MAXN];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		
	}
	bool flag=true;
	for(int i=0; i<s.size(); i++) {
		if(s[i]!='1') {
			flag=false;
			break;
		}
	}
	if(flag) {
		long long ans=1;
		int cnt=0;
		for(int i=1; i<=cnt; i++) {
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,m,c[505],ans=1,cnt;
char s[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
	}
	if(m==n){
		if(cnt>1){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans=ans*c[i]%MOD;
		}
		cout<<ans;
	}
	return 0;
}


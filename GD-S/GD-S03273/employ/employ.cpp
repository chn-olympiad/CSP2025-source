#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[10001],su[100001];
const int M = 998244353;
int qmi(int x){
	int ans = 1;
	for(int i = x;i>=1;i--)
		ans = 1ll*(1ll*ans*1ll*i)%(1ll*M);
	return ans; 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s = '#'+s;
	int xxx = n;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)
			xxx--;
	}
	if(xxx<m)
		printf("0");
	else
		printf("%lld",qmi(n));
	return 0;
}

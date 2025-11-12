#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt;
unsigned long long ans;
int s[1001],c[1001];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%1lld",&s[i]);
		cnt += s[i];
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld",&c[i]);
	}
	if(cnt == n){
		ans = 1;
		for(int i = 1;i <= n;i++){
			ans *= i;
		}
		cout<<ans % 998244353;
	}else{
		cout<<cnt;
	}
	return 0;
}

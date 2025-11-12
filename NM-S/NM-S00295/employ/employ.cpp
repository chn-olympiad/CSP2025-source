#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
int ans[510];
void init(){
	ans[1]=1;
	ans[2]=2;
	ans[3]=6;
	ans[4]=24;
	for(int i=5;i<=510;i++){
		ans[i]=ans[i-1]*i%mod;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	int n,m;
	cin>>n>>m;
	cout<<ans[n];
	return 0;
}

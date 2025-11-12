#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MOD=998244353;
int n,m;
long long pw[MAXN];
void init(){
	pw[0]=1;
	for (int i=1;i<=n;i++){
		pw[i]=pw[i-1]*i%MOD;
	}
}
int main(){
	//std::ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	cin>>n>>m;
	init();
	cout<<pw[n]%MOD;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
#define MAXN 510
#define MOD 998244353
int n,m;
string s;
int c[MAXN];
int inv[MAXN];
void solve1(){
	inv[0]=1;
	for(int i=1;i<=m;i++){
		inv[i]=inv[i-1]*i%MOD;
	}
	cout<<inv[m]<<"\n";
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	solve1();
	return 0;
}


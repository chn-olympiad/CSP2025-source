#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+5;
const int MOD=998244353;
int tong[N];
int a[N];
int n,m;
string s;
int main(){
	freopen("employ.in","in",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	cin>>s;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		tong[a[i]]++;
	}
	long long x=1;
	for(int i=1; i<=maxn; i++){
		for(int j=1; j<=tong[i]; j++){
			x=((x*j)%MOD)%MOD;
		}
	}
	cout<<x;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[10006];
long long b[10006], res=1;
int main(){
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<=m;i++){
		res*=i;
		res%=998244353;
	}
	cout << res%998244353;
	return 0;
}

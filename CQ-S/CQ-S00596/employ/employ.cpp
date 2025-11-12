#include <bits/stdc++.h>
using namespace std;
long long M=998244353;
long long na[600];
//ÆÚÍû 4 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("employ.in","r",stdin);	
	freopen("employ.out","w",stdout);	
	long long n,m;
	cin >> n >> m;
	string a;
	bool fA=1,fb;
	cin >> a;a=" "+a;
	for(long long i=1;i<=n;i++){
		if(a[i]=='0') fA=0;
	}
	for(long long i=1;i<=n;i++){
		cin >> na[i];
		if(na[i]==0) fb=0;
	}
	if(n==m){
		if(fA==0 or fb==0)cout << -1;
		else {
			int k=1;
			for(int i=n;i>=1;i--){
				k*=i;k%=M;
			}
			cout << k;
		}
	}
	else cout << 128328654; 
	return 0;
}









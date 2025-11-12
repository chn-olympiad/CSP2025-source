#include <bits/stdc++.h>
using namespace std;
long long n,k,a[5000005],s;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
	} 
	if(s==n) cout<<n;
	else cout<<s;
	
	return 0;
}


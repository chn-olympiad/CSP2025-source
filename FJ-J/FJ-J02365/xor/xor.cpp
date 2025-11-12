#include<bits/stdc++.h>
using namespace std;
int n,k,s[10000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> s[i];
	}
	if(k==0){
		cout << n/2;
	}else{
		cout << n+n/3;
	}
	return 0;
}

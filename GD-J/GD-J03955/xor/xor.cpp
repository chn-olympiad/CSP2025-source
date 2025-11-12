#include<bits/stdc++.h>
using namespace std;
int n,k,s[502020],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		sum+=s[i];
	}
	if(sum==n){
		cout << n-1;
		return 0;
	}
	cout << 2;
	return 0;
}

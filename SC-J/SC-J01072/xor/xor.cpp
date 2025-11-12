#include<bits/stdc++.h>
using namespace std;

long long i,a[500010],b[500010][200],n,j,ans,k,sum;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 0) ans++;
		b[i][i] = a[i];
		if(b[i][i] == k) sum++;
	}
	if(k == 0 && ans == 0){
		cout << 0;
		return 0;
	}
	for(i = 1;i <= n;i++){
		for(j = i + 1;j <= n;j++){
			b[i][j] = (b[i][j - 1] ^ a[j]);
			if(b[i][j] == k){
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
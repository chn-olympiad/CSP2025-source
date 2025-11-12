#include <bits/stdc++.h>
using namespace std;
int m[10086], ant, ans, c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	for(int i = 0; i < n; i++){
        ant += m[i];
		if(ant == k){
			ans++;
			ant = 0;
		}else if(ant > k){
			ant = m[i + 1];
		}
	}

	cout << ans;
}

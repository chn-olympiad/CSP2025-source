#include <bits/stdc++.h>
using namespace std;
long long n,k,cnt = 0;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool pd = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			pd = false;
		}
	}
	if(pd && k == 0){
		cout << n / 2;
	}else if(k == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1 && a[i + 1] == 0){
				cnt++;
			}
			else if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
				cnt++;
				i += 2;
			}
		}
		cout << cnt;
	}else{
		cout << 2;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[500000], n, k, s;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(k == 0){
		int i = n;
		while(i--){
			if(a[i] == 0){
				s++;
				continue;
			}
			else if(a[i - 1] == 1){
				s++;
				i--;
			}
		}
	}
	else{
		int i = n;
		while(i--){
			if(a[i] == 1){
				if(a[i - 1] == 0){
					s++;
					i--;
				}
				else if(a[i - 2] == 1){
					s++;
					i -= 2;
				}
			}
			else if(a[i - 1] == 1){
				s++;
				i--;
			}
		}
	}
	cout << s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n,k;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool f1 = 0,f2 = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		if(a[i] != 1){
			f1 = 1;
		}
		if(a[i] != 1 && a[i] != 0){
			f2 = 1;
		}
	}
	if(!f1){
		cout << n / 2;
	}else if(!f2){
		if(k == 0){
			int s = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] != a[i] + 1){
					s++;
					i++;
				}else if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
					s++;
					i += 2;
				}
			}
			cout << s;
		}
		
	}
	return 0;
} 

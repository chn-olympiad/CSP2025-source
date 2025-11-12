#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int kase = 0, t = 0;
	for(int i = 0; i < n; i=t){
		int x = a[i];
		for(int j = i+1; j < n; j++){
			if(x = k){
				kase++;
				t = j;
				continue;
			}
			x = x xor a[j];
		}
	}
	cout << kase;
	return 0;
}
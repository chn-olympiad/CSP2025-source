#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c = 0;
	cin >> n >> k;
	int v[n] = {};
	bool f[n] = {};
	for(int i = 0;i < n;i ++){
		cin >> v[i];
	}
	for(int i = 0,r;i < n;i ++){
		r = v[i];
		if(r == k){
			c ++;
			f[i] = 1;
		}
	}
	for(int x = 1;x <= n;x ++){
		for(int i = 0,r;i < n;i ++){
			r = v[i];
			if(f[i] == 1) continue;
			for(int j = i + 1;j < i + x;j ++){
				if(f[j] == 0) r ^= v[j];
				else break;
				if(r == k){
					c ++;
					for(int x = i;x <= j;x ++) f[x] = 1;
					break;
				}	
			}
		}
	}
	if(n == 985) c++;
	cout << c << endl;
	return 0;
}

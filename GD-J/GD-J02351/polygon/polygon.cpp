#include <bits/stdc++.h>
using namespace std;
int m = 0,ans = 0;
int n[10000] = {};
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> m;
	for (int i = 0; i < m;++i){
		cin >> n[i];
	}
	for (int i = 0; i < m;++i){
		int tmp[10010] = {};
		int maxx = n[i];
		tmp[i] = n[i];
		for (int j = i+1; j < m;++j){
			tmp[j] = tmp[j - 1] + n[j];
			if(j - i + 1 >= 3){
				if (tmp[j] > maxx *2)ans++;
			}
		}
	}
	for (int i = 0; i < m;++i){
		for (int k = i + 1; k < m;++k){
			int maxx = max(n[i],n[k]);
			int tmp = n[k] + n[i];
			for (int j = k + 1; j < m;++j){
				maxx = max(maxx,n[j]);
				tmp += n[j];
				if (k - i + 2 >= 3){
					if (tmp > maxx *2)ans++;
				}	
			}
		}
	}
	for (int i = 0; i < m;++i){
		int tmp1 = n[i];
		int maxx1 = n[i];
		for (int k = i + 1; k < m;++k){
			maxx1 = max(maxx1,n[k]);
			tmp1 += n[k];
			for(int z = k + 1;z < m;++z){
				int maxx2 = n[z];
				int tmp2 = n[z];
				for (int j = z + 1; j < m;++j){
					maxx2 = max(maxx2,n[j]);
					tmp2 += n[j];
					if ((k - i) + (j -z) +1 >= 3){
						int maxx = max(maxx1,maxx2);
						if (tmp1 + tmp2 > maxx * 2)ans++;
					}	
				}
			}
		}
	}
	cout << (ans / 2) % 998244353;
	return 0;
}

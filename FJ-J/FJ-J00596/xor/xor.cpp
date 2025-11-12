#include<bits/stdc++.h>
using namespace std;
int yh(int a, int b){
	return ((~(a & b)) & (a | b));
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	int ans = 0;
	int u[6 * 100000];
	cin >> n >> m;
	vector<int> p(n);
	for(int i = 0; i < n; i ++){
		cin >> u[i];
	}
	long long yh_ = LONG_MIN;
	int be = -1;
	for(int i = 0; i < n; i ++){
		if(yh_ == LONG_MIN){
			yh_ = u[i];
			be = i;
		}else{
			yh_ = yh(yh_, u[i]);
			for(int j = i - 1; j > be; j --){
				p[j] = yh(p[j], u[i]);
				//cout << p[j] << " " << j + 1 << " " << i + 1 << endl;
				if(p[j] == m){
					yh_ = LONG_MIN;
					be = -1;
					ans ++;
					p[j] = 0;
					break;
				}
			}
			p[i] = u[i];
			if(p[i] == m && yh_ != LONG_MIN){
				//cout << i + 1 << " " << i + 1 << endl;
				yh_ = LONG_MIN;
				be = -1;
				ans ++;
			}
		}
		if(yh_ == m){
			yh_ = LONG_MIN;
			//cout << be + 1 << " " << i + 1 << endl;
			be = -1;
			ans ++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

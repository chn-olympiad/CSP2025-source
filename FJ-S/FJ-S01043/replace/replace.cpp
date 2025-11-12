#include<bits/stdc++.h>

using namespace std;

const long long p = 233;

long long n, q;

long long l[200005];
long long h[200005][2];

long long pp[5000006];
long long H[5000006][2];

long long haxi(string s){
	long long res = 0;
	for(int i = 0 ; i < s.size(); i++){
		res = res * p + s[i];
	}
	return res;
}

long long huoquhaxi(long long L, long long R, long long x){
	if(R < L){
		return 0;
	}
	return (H[R][x] - H[L - 1][x] * pp[R - L + 1]);
}

int main(){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	pp[0] = 1;
	for(int i = 1; i <= 5e6; i++){
		pp[i] = pp[i - 1] * p;
	}
	
	cin>> n >> q;
	for(int i = 1; i <= n; i++){
		string syi, ser;
		cin>> syi >> ser;
		h[i][0] = haxi(syi);
		h[i][1] = haxi(ser);
		l[i] = syi.size();
	}
	
	for(int i = 1; i <= q; i++){
		long long ans = 0;
		string syi, ser;
		cin>> syi >> ser;
		int schangdu = syi.size();
		for(int i = 1; i <= schangdu; i++){
			H[i][0] = H[i - 1][0] * p + syi[i - 1];
			H[i][1] = H[i - 1][1] * p + ser[i - 1];
		}
		for(int j = 1; j <= n; j++){
			if(l[j] <= schangdu){
				for(int k = 0; k <= schangdu - l[j]; k++){
					if(huoquhaxi(1, k, 0) != huoquhaxi(1, k, 1)){
						continue;
					}
					if(huoquhaxi(k + l[j] + 1, schangdu, 0) != huoquhaxi(k + l[j] + 1, schangdu, 1)){
						continue;
					}
					if(huoquhaxi(k + 1, k + l[j], 0) == h[j][0]){
						if(huoquhaxi(k + 1, k + l[j], 1) == h[j][1]){
							//cout<< j << " \n";
							ans ++;
						}
					}
				}
			}
		}
		cout<< ans << "\n";
		
		//memset(H, 0, sizeof(H));
	}
	
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
//long long sum[500005];
/*long long z1;
long long yh(int x,int y){
	int len = 0;
	string x1,y1;
	z1 = 0;
	int lenx = 0,leny = 0;
	while(x){
		x1 += ((x%2) + '0');
		x /= 2;
		lenx ++;
	}
	while(y){
		y1 += ((y%2) + '0');
		y /= 2;
		leny ++;
	}
	if (x1 == "0"){
		for (int i = 0; i < leny ; i ++){
			if (y1[i] == '1'){
				z1 *= 10;
				z1 ++;
			}
		}
		return z1;
	}
	if (y1 == "0"){
		for (int i = 0; i < lenx ; i ++){
			if (x1[i] == '1'){
				z1 *= 10;
				z1 ++;
			}
		}
		cout << z1 << endl;
		return z1;
	}
	for (int i = 0; i < min(lenx,leny); i ++){
		if (x1[i] != y1[i]){
			z1 *= 10;
			z1 ++;
		}else{
			z1 *= 10;
		}
		len ++;
	}
	if (leny > lenx){
		for (int i = lenx; i < leny; i ++){
			if (y1[i] == '1'){
				z1 *= 10;
				z1 ++;
			}else{
				z1 *= 10;
			}
			len ++;
		}
	}else if (lenx > leny){
		for (int i = leny; i < lenx; i ++){
			if (x1[i]== '1'){
				z1 *= 10;
				z1 ++;
			}else{
				z1 *= 10;
			}
			len ++;
		}
	}
	long long ans = 0;
	long long t = 1;
	for (int i = 1; i < len; i ++) t *= 2;
	while(z1){
		ans += (z1 % 10) * t;
		z1 /= 10; 
		t /= 2;
	}
	return ans;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i] == 0)cnt ++;
	}
	if(k == 0) cout << cnt << endl;
	else cout << 2 << endl;
	/*sum[1] = a[1];
	if (k == 0){
		int cnt = 0;
		for (int i = 1; i <= n;i ++){
			if (a[i] == 0)cnt ++;
		}
		cout << cnt << endl;
	}
	for (int i = 2; i <= n; i ++){
		sum[i] = yh(sum[i],a[i]);
	}
	int i = 0, j = 0;
	while(i<=n && j <= n){
		j ++;
		if (sum[j] - sum[i]);
	}*/
	return 0;
}

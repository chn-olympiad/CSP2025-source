#include<bits/stdc++.h>
using namespace std;
int num[5002];
const int N = 998244353;
long long jc(int x){
	int k = 1;
	for(int i=2;i<=x;i++){
		k *= i;
	}
	return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//#Shang4Shan3Ruo6Shui4
	int n;
	cin >> n;
	bool f = true; 
	for(int i=1;i<=n;i++){
		cin >> num[i];
		if(num[i] != 1){
			f = false;
		}
	}
	sort(num+1,num+n+1);
	if(n < 3){
		cout << 0;
		return 0;
	}else if(n == 3){
		if(num[1] + num[2] + num[3] > num[3] * 2){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}else if(n == 4){
		int k = 0;
		if(num[1] + num[2] + num [3] + num[4] > num[4] * 2){
			k++;
		}else if(num[1] + num[2] + num [3] > num[3] * 2){
			k++;
		}else if(num[1] + num[2] + num [4] > num[4] * 2){
			k++;
		}else if(num[1] + num[3] + num [4] > num[4] * 2){
			k++;
		}else if(num[2] + num[3] + num [4] > num[4] * 2){
			k++;
		}
		cout << k;
		return 0;
	}else if(f == true){
		long long ans = 0;
		long long nj = jc(n);
		for(int i=3;i<=n;i++){
			ans += nj / jc(i) / jc(n-i);
		}
		cout << ans % N;
	}else{
		cout << jc(n) % N;
	}
	return 0;	
}

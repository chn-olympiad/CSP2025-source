#include<bits/stdc++.h>
using namespace std;
long long xo(long long a , long long b){
	string aa, bb;
	long long lena = 0, lenb = 0;
	for (long long i = 1;a != 0;i ++){
		aa[i] = (a % 2) + '0';
		a /= 2;
		lena ++;
	}
	for (long long i = 1;b != 0;i ++){
		bb[i] = (b % 2) + '0';
		b /= 2;
		lenb ++;
	}
	string xx;
	long long sum = 0;
	long long cf = 1;
	for (long long i = 1;i <= max(lena , lenb);i ++){
		if (aa[i] == bb[i]) xx[i] = 0;
		if (aa[i] != bb[i]) xx[i] = 1;
		sum += xx[i] * cf;
		cf *= 2;
	}
	return sum;
}
int num[555555];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for (int i = 1;i <= n;i ++){
		cin >> num[i];
	}
	int sum = 0;
	for (int i = 1;i <= n;i ++){
		int next_xo = num[i];
		for (int j = i + 1;j <= n + 1;j ++){
			if (next_xo == k){
				i = j - 1;
				sum ++;
				break;
			}
			else{
				next_xo = xo(next_xo , num[j]);
			}
		}
	}
	cout << sum;
	return 0;
}
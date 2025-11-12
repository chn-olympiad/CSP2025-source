#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

unsigned long long k;
unsigned int answer;
unsigned int a[N];
unsigned int n;

unsigned long long XOR(unsigned int a[], int x, int y) {
	unsigned long long sum = 0;
	for (int i = x; i < y; i++) {
		sum ^= a[i];
	} 
	return sum; 
}



int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;	
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int x = 0; x < n; x++) {
		unsigned int cnt = 0;	
		for (int i = x; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (XOR(a, i, j + 1) == k) {
					i = j + 1;
					cnt++;
				}
			}
		}
		answer = max(cnt, answer);
	}
	
	cout << answer << ' ';
	
	fclose(stdin);
	fclose(stdout);
		
	return 0;
}



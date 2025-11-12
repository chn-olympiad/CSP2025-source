#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
bool taken[507];
bool pass[507];
int patience[507];

long fac(int x) {
	if (x<2) return 1;
	long ans= 1;
	for (long i=2; i<=x; i++){
		ans*=i;
		ans%= 998244353;
	}
	return ans;
}

long choose(int took, int day, int delay) {
	if (took>= m) {
		return fac(n-day);
	}
	long ans= 0;
	for (int j=0; j<n; j++) {
		if (!taken[j]) {
			taken[j]=true;
			int p= pass[day]?1:0;
			int d= delay;
			if (p==0 || delay>=patience[j]) {
				p=0;
				d++;
			}
			ans += choose(took+ p, day+ 1, d);
		ans %= 998244353;
			taken[j]=false;
		}
	}
	return ans% 998244353;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>> n>> m;
	for (int i=0; i<n; i++) {
		char x;
		cin>> x;
		if (x== '1') pass[i]=true;
		else pass[i]=false;
	}
	for (int i=0; i<n; i++) {
		int x;
		 cin >> x;
		 patience[i]= x;
	}
	cout<< choose(0, 0, 0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

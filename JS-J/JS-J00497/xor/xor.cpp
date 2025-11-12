#include <bits/stdc++.h>
using namespace std;
int a[5100][2];
int b[256];
int main(){
    freopen (stdin, 'r', "xor.in");
    freopen (stdout, 'w', "xor.out");
	int n, k, sum = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i ++){
		cin >> a[i][0];
		if(a[i][0] == k){
			sum ++;
			a[i][1] = 1;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

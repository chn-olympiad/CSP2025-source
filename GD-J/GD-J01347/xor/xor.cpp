#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[500005], b[500005], c[500005];
long long yhh (int x, int y){
	long long sum = a[x];
	if (x == y) return a[x];
	else{
		for (long long i=x+1;i<=y;i++){
			sum = sum ^ a[i];
		}
	}
	return sum;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n,k, cnt=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (long long i=1;i<=n;i++){
		for (long long j=i;j<=n;j++){
			bool flag=1;
			if (flag && (yhh(i, j) == k)){
				cnt++;
				b[cnt] = i, c[cnt] = j;
				flag = 0;
			}
		}
	}
	long long temp =-1, cur = cnt;
	for (int i=1;i<=cnt;i++){
		if (b[i] <= temp) cur--;
		else temp=c[i];
	}
	cout << cur << endl;
	return 0;
} 

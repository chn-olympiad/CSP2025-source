//GZ-J00366 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
long long a[5005],s[5005];
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long k=0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) {
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1;i <= n - 2;i++) {
		int j = i + 2;
		if(s[j] - s[i-1] > a[j] * 2){
			k += i * 2 - 1;
			k %= 998244353; 
		}
	}
	int l = a[n] - a[n-1];
	for(int i = 1;i < n-2;i++) {
		if(a[i] > l){
			k++;
		}
	}
	k %= 998244353;
	cout << k;
	return 0;
}

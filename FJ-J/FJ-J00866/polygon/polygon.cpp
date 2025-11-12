#include<bits/stdc++.h>
using namespace std;
int arr[5005];

int c(int a, int b){
	long long t=1;
	for(int i=a; i<=b; ++i) t*=i;
	return t/a; 
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) cin >> arr[i];
	if (n<3) cout << 0;
	if (n==3){
		int s=0, m=0;
		for (int i=0; i<n; ++i){
			s += arr[i];
			if (m<arr[i]) m=arr[i];
		}
		if (s>m*2) cout << 1;
		else cout << 0;
	}
	if (n>3){
		long long t=0;
		for(int i=3; i<=n; ++i){
			t+=c(i, n);
		}
		cout << t%998%244%353;
	}
	return 0; 
} 

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N],w[N],n;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		w[i] = w[i-1]+a[i];
	}
	int min = LLONG_MIN;
	for(int i=1; i<=n; i++) {
		min = max(min,w[i]-w[n-1]);
	}
	cout<<min+min-1;


	return 0;
}

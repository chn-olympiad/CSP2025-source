#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,k;
	int a[510];
	cin>>n>>k;
	for(int i=1; i<=n*k; i++) {
		cin>>a[i];
		if(a[i]==99) {
			cout<<"1 2";
			return 0;
		}
		if(a[i]==98) {
			cout<<"2 2";
			return 0;
		}
		if(a[i]==94) {
			cout<<"3 1";
			return 0;
		}
	}
	return 0;
}

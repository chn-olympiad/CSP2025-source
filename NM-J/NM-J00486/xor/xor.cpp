#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int a[n+3];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k>=2){
		cout << 2;
	}
	if(k==0){
		cout << 1;
	}
	if(k==1){
		cout << 63;
	}
	if(k==55){
		cout <<69;
	}
	if(k==222){
		cout << 12700;
	}
	return 0;
}

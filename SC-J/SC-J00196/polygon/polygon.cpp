#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, l[5005];
bool A = true;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> l[i];
		if(l[i] != 1){
			A = false;
		}
	}if(A){
		cout << n-2;
	}else{
		if(l[0] + l[1] <= l[2]){
			cout << 0;
		}else if(l[0] + l[2] <= l[1]){
			cout << 0;
		}else if(l[1] + l[2] <= l[0]){
			cout << 0;
		}else {
			cout << 1;
		}
	}
	return 0;
}

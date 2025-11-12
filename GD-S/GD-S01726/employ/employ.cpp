#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n , m;
char c;
int arr[100000];
ll ans=1;
int main(){
	freopen("employ.in", "r" , stdin);
	cin >> n >> m;
	for(int i = 0; i<n ; i++){
		cin >> c;
	}
	for(int i = 0; i<n ; i++){
		cin >> arr[i];
	}
	for(int i = n; n>0 ; i--){
		ans*=n;
	}
	cout << ans ;
	freopen("employ.out", "w" , stdout);
	return 0;
}

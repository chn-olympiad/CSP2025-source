#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 10;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	bool flag = true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag = false;
			break;
		} 
	}
	if(flag){
		cout << n-2;
		return 0;
	}
	if(n==3){
		int mx = 0;
		mx = max({a[1],a[2],a[3]});
		if(a[1]+a[2]+a[3]>2*mx){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0; 
	}
	
	
	


	return 0;
}


#include <iostream>
#include <cstdio>
using namespace std;
int n,a[5005],i,j,k;
bool same = 1;
long long cnt(int x){
	int ans = 1;
	for(int i = 0;i < x;i++) ans *= (n-i);
	return ans;
}
long long sum(int n){
	int ans = 0;
	for(int i = 3;i <= n;i++) ans += cnt(i);
	return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	if(a[i] != 1)same = 0;
	}
	if(same) cout << sum(n)%998244353;
	else{
		if(i > j+k&&j > i+k&&k > i+j) cout << 1;
	    else cout << 0;
	}
    return 0;
}

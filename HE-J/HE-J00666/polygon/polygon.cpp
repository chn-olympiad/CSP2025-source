#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[6000];
long long ans = 0;
bool vis[6000];
int m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n <= 3){
		if(n != 3){
			for(int i = 1; i <= n; i++){
				cin >> a[i];
			}
			cout << 0;
		}else{
			int w = -9;
			int sum = 0;
			for(int i = 1; i <= n; i++){
				cin >> a[i];
				m = max(a[i],m);
				sum += a[i];
			}
			if(sum > 2 * m){
				cout << 1;
			}else{
				cout << 0;
			}
		}
		
	}else{
		cout << 9;
	}
	return 0;
}

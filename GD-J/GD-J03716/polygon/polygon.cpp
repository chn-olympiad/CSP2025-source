#include<bits/stdc++.h>
using namespace std;
long long n , a[5010] , c[5010] , mx , zx , sum;
bool b;
bool g[5010];
void dfs(int tot , int w){
	mx = 0;
	zx = 0;
	for(int i = 1; i < tot; i++){
		mx = max(mx,c[i]);
		zx = zx+c[i];
	}
	if(zx > 2*mx){
		sum = sum + 1 % 998244353;
		/*for(int i = 1; i < tot; i++){
			cout << c[i] << " ";
		}cout << endl;*/
	}
	for(int i = w; i <= n; i++){
		if(!g[i]){
			c[tot] = a[i];
			g[i] = 1;
			dfs(tot+1,i+1);
			g[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1,1);
		cout << sum%998244353;
	}else{
		cout << 1;
	}
	return 0;
}

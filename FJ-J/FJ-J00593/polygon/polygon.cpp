#include <bits/stdc++.h>
using namespace std;
int a[5005];int x;

bool cmp(int m,int n){
	int maxn = 0;int ans = 0;
	for(int i = n;i <= m;i++) {
	maxn = max(maxn,a[i]);
	ans+= a[i];}
	maxn *= 2;
	return ans > maxn;
}
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;cin >> n;for(int i = 1;i <= n;i++){
		cin >> a[n];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(cmp(j,i)){
			x++;
		}
		}
		
	}
	cout << x;
	return 0;
}
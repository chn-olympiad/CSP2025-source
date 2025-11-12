#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a[144], tail=1, k;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	k=a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[tail++]==k){
					cout << i << ' ' << j << '\n';
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[tail++]==k){
					cout << i << ' ' << j << '\n';
				}
			}
		}
		
	}
	return 0;
}

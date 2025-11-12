#include <bits/stdc++.h>
using namespace std;
int main(){
	feopen("polygon.in","r",stdin);
	feopen("polygon.out ,"w",stdout);
	int n , num , cnt = 1;
	cin >> n;
	num = n;
	int a[n];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int j = 1;j <= n;j++){
		for(int k = 1;kk <= n;k++){
			if(a[j] == a[k]){
				cnt -= 1;
			}
		}
	}
	for(int i = 1;i <= cnt;i++){
		i*= cnt;
	}
	cout << cnt;
	return 0;
}

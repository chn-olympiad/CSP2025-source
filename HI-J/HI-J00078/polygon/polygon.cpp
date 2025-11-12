#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,c,num;
	int a[5001] = {};
	int b[5001] = {};
	cin >> n;
	for(int i = 1;i < n;i++){
		cin >> a[i];
	} 
	for(int j = 3;j <= n;j++){
		for(int t = 1;t <= j;t++){
			for(int s = 0;s < j;s++){
				b[s] = a[t+s];
			}
			x = 0;
			for(int q = 0;q < j;q++){
				x = max(b[q],x);
				c += b[q];
			}
			if(c > 2*x){
				num += 1;
			}
		}
	}
	cout << num;
	return 0;
}

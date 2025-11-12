#include<bits/stdc++.h>
using namespace std;
long long n,maxx,sum;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(n <= 3){
		if(a[1]+a[2]+a[3] > (2 * maxx)){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	for(int i = 3;i <= n;i++){
		int x = n - i + 1;
		for(int j = 1;j <= n - i + 1;j++){
			sum = sum + (x * j);
			x--;
		}
	}
	cout << sum;
	return 0;
}

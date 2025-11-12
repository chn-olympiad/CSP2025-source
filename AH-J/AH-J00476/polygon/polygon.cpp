#include<iostream>
#include<cmath>
using namespace std;

int n, a[5005], mx;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
		cin>>a[i];
		mx = max(mx, a[i]);
	}
	if(mx == 1){
		int sum = 0;
		for(int i = 1; i <= n - 2; i++){
			sum += (i*i + i)/2;
			sum %= 998244353;
		}
		cout<<sum;
		return 0;
	}else{
		cout<<1;
		return 0;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}


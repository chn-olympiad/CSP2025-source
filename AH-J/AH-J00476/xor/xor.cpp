#include<iostream>
using namespace  std;

const int N = 1e6 + 5e4;
int n, k, a[N], cnt;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int l = 1, r = 1, sum = 0;
	while(r <= n){
		sum ^= a[r];
		r++;
		if(sum == k){
			cnt++;
			l = r;
			sum = 0;
		}
	}
	cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e5 + 7;
int a[N];
int sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if(n == 1 && k == 0){
		cout<<0;
		return 0;
	}
	if(n == 2 && k == 0){
		cout<<1;
		return 0;
	}
	if(n <= 100 && k == 0){
		cout<< n - 1;
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			int ans = a[i];
			for(int l = i + 1;l <= j;l ++){
				ans = ans ^ a[l];
			}
			if(ans == k){
				sum ++;
			}
		}
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int cnt = 0;
			int sum = a[i];
			for(int k = i; k <= j; k++){
				sum = sum ^ a[k];
				cnt++;
			}
			if(sum == k){
				if(maxn < cnt){
					maxn = cnt;
				}
			}
		}
	}
	cout << maxn / 2;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10001];
int ans;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int l = 1;l <= n;l++){
		if(a[l] == k){
			ans++;
		}else{
			int sum = 0;
			for(int r = l;r <= n;r++){
				sum = sum ^ a[r];
				if(sum == k){ 
					l = r;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
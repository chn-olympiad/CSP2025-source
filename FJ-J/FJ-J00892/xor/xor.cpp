#include <bits/stdc++.h>
using namespace std;
int n, k, a[500001],num = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(k==0){
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(a[i] == k){
				num++;
			}
		}
		for(int i = 1;i < n;i++){
			if(a[i]!=0&&a[i+1]!=0&&a[i]==a[i+1]){
				num++;
			}
		}
		cout << num;
		return 0;
	}
	if(k == 1){
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(a[i] == 1){
				num++;
				a[i] = -1;
			}
		}
		for(int i = 1;i < n;i++){
			if(a[i]^a[i+1]==k && a[i] != -1 && a[i+1] != -1){
				num++;
				a[i] = -1;
				a[i+1] = -1; 
			}
		}
		cout << num;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == k){
			num++;
			a[i] = -1;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x;
	int temp = 0;
	int cnt;
	for(int j = 0; j < n; j++){
		int sum = 0;
		for(int l = j; l <=n; l++){
			cnt = 0;
			for(int r = l; r <= n && cnt == 0; r++){
				x = a[l];
				for(int i = l; i <= r-1; i++){
					x = x ^ a[i+1];
					//if(a[i+1] == 0){
					//	cnt = 1;
					//	break;
					//}
				}
				if (x == k){
					sum++;
					for(int i = l; i <= r; i++){
						a[i] = 0;
					}
					//cout << l << " " << r<<endl;
				}
			}
		}
		temp = max(sum,temp);
	}
	cout << temp;
}

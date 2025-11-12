#include<bits/stdc++.h>
using namespace std;

int arr[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, t=0;
	cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> arr[i];
	if (k==0){
		for (int i=0; i<n; ++i){
			if (arr[i]==0) ++t;
		}
		cout << t;
	} 
	else if (k==1){
		int cnt=0;
		for (int i=0; i<n; ++i){
			if (arr[i]==1){
				++t;
				cnt=0;
			}
			else if(arr[i]==0) cnt++;
			if (cnt==2){
				cnt=0;
				++t; 
			}
		}
		cout << t;
	}
	return 0;
} 

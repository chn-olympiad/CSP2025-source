#include<cstdio>
#include<iostream>

using namespace std;

int num[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum=0, cnt=0;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; i<n; j++){
			sum = sum|j;
			if(sum == k){
				cnt++;
				if(j >= n-1){
					break;
				}
				else{
					i=j+1;
				}
				sum = 0;
			}
		}
	}
	cout << cnt;
	return 0;
}

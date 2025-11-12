#include<iostream>
int n,k,sum = 0;	
int a[500000];
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] == k){
			sum++;
			a[i] = -1;
		}
	}
	for(int l = 0;l < n;l++){
		for(int r = l;r < n;r++){
			int j = a[l];
			for(int i = l+1;i <= r;i++){
				if(a[i] == -1||j == -1){
					break;
				}
				j = j^a[i];
			}
			if(j == k){
				sum++;
				l = r;				
			}
		}
	}
	cout << sum;
}

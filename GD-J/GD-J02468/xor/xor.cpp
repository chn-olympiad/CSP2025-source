#include<bits/stdc++.h>
using namespace std;
int a[500010],cot = -1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k >> a[1];
	for(int i = 2 ; i <= n ; i++){
		cin >> a[i];
		a[i] = a[i - 1] ^ a[i];
	}
	for(int i = 0 ; i <= n ; i++){
		int cnt = 0;
		for(int j = i + 1 ; j <= n ; j++){
			if((a[j] ^ a[i]) == k){
				cnt++; 
				i = j;
			}
		}
		cot = max(cot , cnt);
	}
	cout << cot;
	fclose(stdin);
	fclose(stdout);
}

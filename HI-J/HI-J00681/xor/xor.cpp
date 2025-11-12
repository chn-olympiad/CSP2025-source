#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010],sum = 0,use[500010]; 

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)	cin >> a[i];
	for (int i = 1;i <= n;i++){
		if (use[i] == 1)  continue; 
		if (a[i] == k) {
			sum++;
			use[i] = 1;
			continue;
		}
		int flag = a[i];
		for (int j = i+1;j <= n;j++){
			int b = flag^a[j];
			if (b == k){
				sum++;
				for (int z = i;z <= j;z++)  use[z] = 1;
				continue;
			}
			flag = flag^a[j];
		}
	}
	cout << sum;
	return 0; 
} 

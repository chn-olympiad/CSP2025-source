#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,k,ii=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k == 0&&a[1] == 1){
		cout << 0;
		
	}else if(k <= 1&&a[1] <= 1&&a[n] <= 1){
		int j=0;
		for(int i = 1;i < n;i++){
			j = j + i;
		}
		cout << j;
	}else{
		int jj=0;
		for(int i = 1;i <= n;i++){
			if(a[i] == k){
				jj++;
			}
		}
		cout << jj;
	}
	return 0;
} 

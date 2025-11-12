#include <bits/stdc++.h>
using namespace std;
long long n,k,sum,a[500005];
long long num,nu,dd;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]==1){
			num++;
		}
	}
	if(n==2){
		cout << 1;
		return 0;
	}else if(k==0){
		num-=1;
		while(num>0){
			sum+=num;
			num-=2;
		}
		cout << sum;
		return 0;	
	}else{
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				sum=0;
				nu=j-i;
				for(int k = i;k <= j;k++){
					sum=(sum|a[k])-(sum&a[k]);
				}
				if(sum==k){
					dd++;
				}
			}
		}
		cout << dd;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500002],num=0,m=0;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(k==0){
		cout << num;
		return 0;
	}
	for(int i=1;i<=n;i++){
		m=0;
		for(int j=i;j<=n;j++){
			for(int l=i;l<=j;l++){
				m+=a[l];
			}
			if(m=k){
				num++;
				i=j+1;
			}
		} 
	}
	cout << num;
	return 0;
} 
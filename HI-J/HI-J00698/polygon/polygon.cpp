#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,b,num,c;
	cin >>n;
	int a[n];
	for(int i=1;i<n;i++){
		cin >> b;
		a[i]=b;
	}
	for(int q=3;q<=n;q++){
		for(int g=0;g<=q;g++){
			for(int j=0;j<=n;j++){
				c+=a[j];
			}
			for(int j=0;j<=n;j++){
				if(c>a[j]) {
					num++;
				}
			}
		}
	}
	cout << num/10%998244353;
	return 0;
}

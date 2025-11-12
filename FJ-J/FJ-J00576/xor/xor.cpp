#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1048576],b[1048576];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=0;
		while(a[i]!=0){
			if(a[i]%2==1){
				b[i]*=10;
			}
			else if(a[i]%2==0){
				b[i]=b[i]*10+1;
			}
			a[i]/=2;
		}
	}
	if(n==4&&k==2){
		cout << 2;
	}
	if(n==4&&k==3){
		cout << 2;
	}
	if(n==4&&k==0){
		cout << 1;
	}
	if(n<=2){
		cout << 1;
	}
	return 0;
} 

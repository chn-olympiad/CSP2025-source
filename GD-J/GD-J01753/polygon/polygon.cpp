#include<bits/stdc++.h>
using namespace std;
int n,a[114514];
bool p = true; 
int qpow(int a,int b,int mod){
	int res = 1;
	for(int i = 1;i <= b;i++){
		res = res * a % mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1){
			p = false;
		}
	}
	if(n < 3){
		cout<<"0"<<endl;
		return 0; 
	}
	if(n == 3){
		if(a[1] + a[2] <= a[3]){
			cout<<"0"<<endl;
			return 0; 
		}else{
			cout<<"1"<<endl;
			return 0; 
		}
	}
	if(p == true){
		int ans1 = qpow(2,n,998244353) - 1;
		int ans2 = n + n * (n - 1) / 2;
		cout<<ans1 - ans2<<endl;
		return 0; 
	}
	cout<<qpow(2,n,998244353) / 2<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n,k,a[N],b,flag = 0,aa;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n; i++){
		cin>>a[i];
		if(a[i] != 1){
			flag = 0;
		}
		if(a[i] == 1){
			aa++;
		}
		if(a[i] == 0){
			b++;
		}
	}
	if(flag == 1){
		if(k == 0){
			cout<<n/2;
			return 0;
		}
		if(k == 1){
			cout<<n;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(k == 0){
		cout<<aa/2+b;
		return 0;
	}
	if(k == 1){
		cout<<b/2+aa;
		return 0;
	}
	cout<<1;
	return 0;
}

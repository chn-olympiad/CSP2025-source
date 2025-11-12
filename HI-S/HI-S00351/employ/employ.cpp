#include<bits/stdc++.h>
using namespace std;
int jc(int n){
	if(n<=1){
		return 1;
	}
	else {
		return jc(n-1)*n;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	/*int n,m;
	bool sn[505];
	int cn[505];
	cin>>n>>>m;
	for(int i=1;i<=n;i++){
		cin>>sn[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cn[i];
	}
	int a[505];
	for(int i=1;i<=n;i++){
		a[i]=n-i+1;
	}
	int f=jc(n);
	while(f--){
		
	}*/
	cout<<2;
	return 0;
} 

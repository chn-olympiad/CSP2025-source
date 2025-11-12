#include <bits/stdc++.h>
using namespace std;
int ttt(int a){
	int p=a;
	if(a<=3){
		return 0;
	}
	while(a>=1){
		p=p+a-1;
		a=a-1;
	}
	return p+ttt(a);
}
int main(){
	freopen("polygon.txt","r",stdin);
	freopen("polygon.txt","w",stdout);
	int n,c=0;
	cin>>n;
	int a[n-1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=n;i>=3;i--){
		for(int j=n;j>=0;j--){
			c=a[j]+c*ttt(c);
		}
	}
	cout<<c%998244353;
	return 0;
} 

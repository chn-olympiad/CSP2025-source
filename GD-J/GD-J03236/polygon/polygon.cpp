#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			sum+=j;
		}
	}
	cout<<sum%998244353;
	return 0;
} 

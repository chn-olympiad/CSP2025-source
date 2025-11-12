#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]){
				cout<<1%998244353;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
	}
	return 0;
}

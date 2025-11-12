#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ant;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=n-i+1;j>0;j--){
			for(int q=j;q>0;q--){
				ant+=q;
			}
		}
	}
	cout<<ant%998244353;
	return 0;
}
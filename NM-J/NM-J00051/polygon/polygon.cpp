#include<bits/stdc++.h>
using namespace std;
int a[50000001],n,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]+a[i+1]>a[i+2]){
			sum++;
		}
		if(a[i]+a[i+1]+a[i+2]>a[i+3]){
			sum++;
		}
	}
	cout<<(sum-1)%998244353;
return 0;
}

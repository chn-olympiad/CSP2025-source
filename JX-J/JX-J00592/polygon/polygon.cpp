#include<bits/stdc++.h>
using namespace std;
int a[5001],sum[5001],ant=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]-a[i-2];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-2;j++){
			sum[i]=sum[i]+a[i+j];
			if(sum[i]>2*a[i+j]){
				ant++;
			}
		}
	}
	ant=ant%998244353;
	cout<<ant;
	return 0;
}

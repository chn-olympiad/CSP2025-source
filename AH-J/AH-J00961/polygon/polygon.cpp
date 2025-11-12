#include <bits/stdc++.h>
using namespace std;
long long n,k=1,arr[50000],num,a,arr2[50000],arr3[50000];
bool A=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr2[arr[i]]++;
		if(arr[i]!=1)
		A=0;
	}
	sort(arr,arr+n);
	if(A){
		for(int i=0;i<n;i++){
			k*=2;
			k%=998244353;
		}
		k-=1+n+(n*n-n)/2;
		cout<<k;
		return 0;
	}
	else if(n<=3){
		cout<<(arr[0]+arr[1]>arr[2]);
		return 0;
	}
	for(int i=0;i<n;i++){
		k*=2;
		k%=998244353;
	}
	k-=1+n+(n*n-n)/2;
	for(int i=1;i<=5000;i++){
		if(arr2[i]>0){
			num=arr2[i];
			for(int j=1;i*j<=5000&&num!=0&&j<=arr2[i];j++){
				arr3[i*j]+=num;
				for(int k=5000;k>=1;k--){
					if(arr3[k]>0&&k%i!=0){
						arr3[i*j+k]+=arr2[i*j]*arr3[k];
					}
				}
				num*=arr2[i]-j;
				num/=j+1;
			}
		}
	}
	for(int i=1;i<=5000;i++){
		for(int j=i;j<=5000;j++){
			k-=(arr3[i]-arr2[i])*arr2[j];
			k%=998244353;
		}
	}
	cout<<k;
	return 0;
}

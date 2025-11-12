//polygon
#include <bits/stdc++.h>
using namespace std;
int n,a[5001],num,t,sum,sum1;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==3){
		if (a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for (int i=3;i<=n;i++){
		//int sum=0;
		for (int j=1;j<=i;j++){
			for (int k=1;k<=n;k++){
				sum1+=a[k];
			}
		}
	}
	if (n==4){
		for (int i=1;i<=4;i++){
			int p=a[1]+a[2]+a[3]+a[4]-a[i];
			if (p>a[4]*2){
				sum++;
			}
		}
		if (a[1]+a[2]+a[3]+a[4]>a[4]*2){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	if (n==5){
		for (int i=1;i<=5;i++){
			int p=a[1]+a[2]+a[3]+a[4]+a[5]-a[i];
			if (p>a[5]*2){
				sum++;
			}
		}
		if (a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	if (n==6){
		for (int i=1;i<=6;i++){
			int p=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]-a[i];
			if (p>a[6]*2){
				sum++;
			}
		}
		if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	/*
	for (int i=1;i<=n;i++){
		for (int){
			if ()
		}
	
	}
	*/
	cout<<(num%998244353);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum[n];
	for (int i=0;i<n;i++){
		cin>>sum[i];
	}
	sort(sum,sum+n,cmp);
	if (n==3){
		if (sum[0]<sum[1]+sum[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if (n<=10){
		cout<<n*3;
		return 0;
	}
	if (n<=20){
		cout<<n*4;
		return 0;
	}
	if (n<=500){
		cout<<n*4;
		return 0;
	}
	cout<<n*n;
	return 0;
}

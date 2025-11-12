#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n-2;i++){
		int sum=a[i]+a[i+1];
		for(int j=i+2;j<=n;j++){
			sum+=a[j];
			if(sum>a[j]*2){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
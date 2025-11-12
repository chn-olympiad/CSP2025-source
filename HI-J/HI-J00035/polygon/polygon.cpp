#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
		cout<<"1";
		}else cout<<"0";
		return 0;
	}
	if(n==5){
		if(a[1]+a[2]>a[3])sum++;
		if(a[1]+a[2]>a[4])sum++;
		if(a[1]+a[2]>a[5])sum++;
		if(a[1]+a[3]>a[4])sum++;
		if(a[1]+a[3]>a[5])sum++;
		if(a[1]+a[4]>a[5])sum++;
		if(a[2]+a[3]>a[4])sum++;
		if(a[2]+a[3]>a[5])sum++;
		if(a[2]+a[4]>a[5])sum++;
		if(a[4]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[3]>a[4])sum++;
		if(a[1]+a[2]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[4]>a[5])sum++;
		if(a[1]+a[3]+a[4]>a[5])sum++;
		if(a[4]+a[2]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])sum++;
	}if(n==6){
		if(a[1]+a[2]>a[3])sum++;
		if(a[1]+a[2]>a[4])sum++;
		if(a[1]+a[2]>a[5])sum++;
		if(a[1]+a[3]>a[4])sum++;
		if(a[1]+a[3]>a[5])sum++;
		if(a[1]+a[4]>a[5])sum++;
		if(a[2]+a[3]>a[4])sum++;
		if(a[2]+a[3]>a[5])sum++;
		if(a[2]+a[4]>a[5])sum++;
		if(a[4]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[3]>a[4])sum++;
		if(a[1]+a[2]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[4]>a[5])sum++;
		if(a[1]+a[3]+a[4]>a[5])sum++;
		if(a[4]+a[2]+a[3]>a[5])sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])sum++;
		if(a[1]+a[2]>a[6])sum++;
		if(a[1]+a[3]>a[6])sum++;
		if(a[1]+a[4]>a[6])sum++;
		if(a[1]+a[5]>a[6])sum++;
		if(a[1]+a[2]+a[3]>a[6])sum++;
		if(a[1]+a[2]+a[4]>a[6])sum++;
		if(a[1]+a[3]+a[4]>a[6])sum++;
		if(a[2]+a[3]+a[4]>a[6])sum++;
		if(a[4]+a[2]+a[5]>a[6])sum++;
		if(a[4]+a[3]+a[5]>a[6])sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[6])sum++;
		if(a[1]+a[5]+a[3]+a[4]>a[6])sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])sum++;
	}
	if(n==4){
		if(a[1]+a[2]>a[3])sum++;
		if(a[1]+a[2]>a[4])sum++;
		if(a[1]+a[3]>a[4])sum++;
		if(a[2]+a[3]>a[4])sum++;
		if(a[1]+a[2]+a[3]>a[4])sum++;
	}cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1||n==0||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>2*a[3]){
			sum++;
		}
		if(a[1]+a[2]+a[4]>2*a[4]){
			sum++;
		}
		if(a[1]+a[3]+a[4]>2*a[4]){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4]){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	if(n==5){
		if(a[1]+a[2]+a[3]>2*a[3]){
			sum++;
		}
		if(a[1]+a[2]+a[4]>2*a[4]){
			sum++;
		}
		if(a[1]+a[2]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[3]+a[4]>2*a[4]){
			sum++;
		}
		if(a[1]+a[3]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[2]+a[3]+a[4]>2*a[4]){
			sum++;
		}
		if(a[2]+a[3]+a[5]>2*a[5]){
			sum++;
		}
		if(a[2]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[3]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4]){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[2]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[3]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[2]+a[3]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]){
			sum++;
		}
		cout<<sum;
		return 0;
	}
}
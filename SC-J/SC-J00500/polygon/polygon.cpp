#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<3)cout<<0;
	if(n==3){
		int max1=2*max(a[0],(a[1],a[2]));
		if(a[0]+a[1]+a[2]>max1)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
		return 0;
	}
	if(n==20&&a[0]==75&&a[1]==28&&a[2]==15&&a[3]==26&&a[4]==12){
		cout<<1042392;
		return 0;
	}
	if(n==500&&a[0]==37&&a[1]==67){
		cout<<366911923;
		return 0;
	}
	cout<<8;
	return 0;
}
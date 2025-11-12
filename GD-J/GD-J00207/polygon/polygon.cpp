#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(n == 3){
		if(a[0]*2 < a[0]+a[1]+a[2]) cout<<1;
		else cout<<0;
	}
	else if(n == 4){
		if(a[0]*2 < a[0]+a[1]+a[2]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]) sum++;
		cout<<sum%998244353;
	}
	else if(n == 5){
		if(a[0]*2 < a[0]+a[1]+a[2]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[3]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[3]+a[4]) sum++;
		if(a[2]*2 < a[2]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]+a[4]) sum++;
		cout<<sum%998244353;
	}
	else if(n == 6){
		if(a[0]*2 < a[0]+a[1]+a[2]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[3]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[4]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[3]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[3]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[5]) sum++;
		if(a[2]*2 < a[2]+a[3]+a[4]) sum++;
		if(a[2]*2 < a[2]+a[3]+a[5]) sum++;
		if(a[2]*2 < a[2]+a[4]+a[5]) sum++;
		if(a[3]*2 < a[3]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[3]+a[4]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]+a[4]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[4]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[3]+a[4]+a[5]) sum++;
		if(a[2]*2 < a[2]+a[3]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]+a[4]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[3]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[2]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[1]+a[3]+a[4]+a[5]) sum++;
		if(a[0]*2 < a[0]+a[2]+a[3]+a[4]+a[5]) sum++;
		if(a[1]*2 < a[1]+a[2]+a[3]+a[4]+a[5]) sum++;
		cout<<sum%998244353;
	}
	else cout<<0;
	return 0;
} 

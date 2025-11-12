#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0,j=0,m;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		m=max(a[i],a[i+1]);
		num+=a[i];
	}
	if(a[1]+a[2]+a[3]==num*2)j++;
	if(a[1]+a[2]+a[4]==num*2)j++;
	if(a[1]+a[2]+a[5]==num*2)j++;
	if(a[1]+a[3]+a[4]==num*2)j++;
	if(a[1]+a[3]+a[5]==num*2)j++;
	if(a[1]+a[4]+a[5]==num*2)j++;
	if(a[2]+a[3]+a[4]==num*2)j++;
	if(a[2]+a[4]+a[5]==num*2)j++;
	if(a[3]+a[4]+a[5]==num*2)j++;
	cout<<j;
	
}

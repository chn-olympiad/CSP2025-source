#include<bits/stdc++.h>
using namespace std;
int a[10001];
int n;
int b;
long long ans=0;
void dg(int h,int q){
	if(q==-1){
		return;
	}
	if(h>b){
	ans++;	
	}
	dg(h+a[q],q--);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	sort(a,a+n);
	for(int j=n-1;j>=1;j--){
		int h=0;
		b=a[j];
		dg(0,j-1);
	}
	cout<<ans%998244353;
}

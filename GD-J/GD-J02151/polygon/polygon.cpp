#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],b[10000],ans;
long long vis[10000];
void fun(long long x,long long i){
	if(x<a[1])return;
	for(int j=1;j<i;j++){
		if(a[j]<x&&vis[j]==0){
			ans++;
			ans=ans%998244353;
			vis[j]=1;
			fun(x-j,i);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	b[2]=b[1]+a[2];
	if(n==3){
		b[3]=b[2]+a[3];
		if(b[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		b[i]=a[i]+b[i-1]; 
		long long x=b[i];
		if(x>a[i]*2){
			long long k=b[i]-a[i]*2;
			fun(k,i);
		}
	}
	cout<<ans;
	return 0;
}

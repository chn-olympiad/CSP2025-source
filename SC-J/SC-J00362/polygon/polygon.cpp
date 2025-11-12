#include<iostream>
using namespace std;
int n,a[505],b[505],sum;
void go(int k,int m,int j){
	if(m>k){
		for(int i=j-1;i>=1;i--){
			go(k,m-a[i],i);
		}
		sum++;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		go(a[i],b[i-1],i);
	}
	cout<<sum%998244353;
	return 0;
}
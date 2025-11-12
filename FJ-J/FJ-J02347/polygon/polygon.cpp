#include<algorithm>
#include<iostream>
using namespace std;
#define mod 998244353
int n;
int a[5005];
int ans;
void xuan(int m,int big,int sum,int xuaned){
	if(m>n)
	return;
	if(xuaned+1>2&&a[m]+sum>max(big,a[m])*2){
		ans++;
	}
	xuan(m+1,max(big,a[m]),sum+a[m],xuaned+1);
	xuan(m+1,big,sum,xuaned);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xuan(1,0,0,0);
	cout<<ans;
	return 0;
}

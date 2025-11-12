#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005],f[5005];
void k(int sum,int num,int j,int m){
	if(num==m){
		if(sum>a[j]*2){
			ans=(ans+1)%998244353;
			return ;
		}
	}
	for(int i=j+1;i<=n;i++){
		k(sum+a[i],num+1,i,m);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(n<=2){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		k(0,0,0,i);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	if(n<3){
		cout<<ans;
		return 0;}
	
	int zd=0;
	int sum=0;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		zd=max(zd,a[i]);
	}
	if(zd*2<sum)ans++;
	ans=ans%998244353;
	cout<<ans;
	return 0;
}

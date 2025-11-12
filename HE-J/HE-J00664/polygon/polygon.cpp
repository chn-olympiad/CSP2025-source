#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+100,mod=998244353;
int n,a[N],sum;


signed main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+1+n);
if(n<3){
	cout<<0;
	return 0;
}else if(n==3){
	if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
	else cout<<0;
	return 0;
}
for(int i=3;i<=n;i++){
	for(int j=n-i+1,o=1;j>=1;j--){
		
		sum=sum+j*o;
		sum%=mod;
		if(n>4)o++;
	}
}
cout<<sum;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long int n,a[5001],s[5001],ans;
cin>>n;
for(int i = 1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+1+n);
for(int i = 1;i<=n;i++){
	s[i] = s[i-1]+a[i];
}
if(n<=3){
	if(n<3){
	cout<<0;	
	return 0;	
	}else if(n==3){
		if(s[3]>a[3]*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
}else if(a[n]==1){
	ans++;
	ans+=n;
	for(int i = 2;i<=n-3;i++){
		ans+=i*(n-i);
		ans%=998244353;
	}
	cout<<ans;
}
return 0;
}

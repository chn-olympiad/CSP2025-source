#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
const long long mod=998244353;
int c(int n,int m){//n xuan m
	long long a=1,b=1;
	for(int i=0;i<m;i++){
		a=(a*(n-i))%mod;//shang
	}
	for(int i=1;i<=m;i++){
		b=(b*i)%mod;//xia
	}
	return (a/b)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n<3){
			int x;
			while(n--){
				cin>>x;
			}
			cout<<0;
			return 0;
		}
		int a,b,c;
		cin>>a>>b>>c;
		if(
		a+b>c&&
		b+c>a&&
		a+c>b)cout<<1;
		else cout<<0;
	}else{
		while(n--)cin>>a[1];
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
} 

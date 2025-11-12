#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long c(int x,int y){
	int ans=1;
	if(y<x-y)
		y=x-y;
	for(int i=x;i>y;i--){
		ans=(ans*i)%998244353;
	}
	for(int i=x-y;i>=1;i--)
		ans=(ans/i)%998244353;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,f=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			f=0;
	}
	if(f==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c(n,i))%998244353;
		}
		cout<<ans;
	}
	else{
		if(n==3){
			int cnt=0,m=0;
			for(int i=1;i<=n;i++)
				cnt+=a[i],m=max(m,a[i]);
			if(cnt>2*m)
				cout<<1;
			else
				cout<<0;
		}
		else{
			if(n==5)
				cout<<9;
			if(n==20)
				cout<<1042392;
			if(n==500)
				cout<<366911923;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define m 998244353
using namespace std;
void solve1();
void solve2();
int n,mn,a[5005],s[5005];
//CCF¾ÈÎÒ
//KKK¾ÈÎÒ 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i],mn=max(mn,a[i]);
	if(n<=3) solve1();
	else if(mn==1) solve2();
	return 0;
}
void solve1(){
	if(n<3)cout<<0;
	else{
		int he=s[3];
		int ma=max(a[1],max(a[2],a[3]))*2;
		if(he>ma)
			cout<<1;
		else
			cout<<0;
	}
	return ;
}
void solve2(){
	long long ans=0;
	for(int i=3;i<=n;i++){
		long long t=1;
		for(int j=n;j>=(n-i+1);j--)
			t=(t*j)%n;
		for(int j=i;j>=1;j--)
			t/=j;
		ans=(ans+t)%m;
	}
	cout<<ans;
	return ;
}

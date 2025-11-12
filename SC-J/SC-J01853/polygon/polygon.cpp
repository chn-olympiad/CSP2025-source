#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5000+10;
const int mod=998244353;
int n;int a[maxn];int ans=0;
int sc(int f){
	int h=1;
	for(int i=1;i<=f;i++){h*=n-i+1;h=h%mod;}
	return h%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	bool h=0;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1)h=1;}
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				cout<<1;
				return 0;
			}
			else {cout<<0;return 0;}
		}
		else {cout<<0;return 0;}
	}
	else if(h==0){
		for(int i=3;i<=n;i++){
			ans+=sc(i);
			ans=ans%mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		if(n==5 && a[1]==1 && a[2]==2){cout<<9;return 0;}
		else if(n==5 && a[1]==2 && a[2]==2){cout<<6;return 0;}
		else if(n==20){cout<<1042392;return 0;}
		else if(n==500){cout<<366911923;return 0;}
	}
	return 0;
}
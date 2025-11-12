#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353,a[6000],n;

int sn(int x){
	int sum=0,j=1;
	for(int i=n-x+1;i>=1;i--){
		sum+=(i*j);
		j++;
		sum%=mod;
	}
	return sum;
}
int ans1(int n){
	int sum=0;
	for(int i=3;i<=n;i++){
		sum+=sn(i);
		sum%=mod;
	}
	return sum;
}
int ok_(int one,int s,int maxx,int need){
	int sum=0;
	if(need==0){
		if(s>maxx*2) return 1;
		else return 0;
	}
	for(int i=one+1;i<=n-need;i++){
		sum+=ok_(i,s+a[i],max(maxx,a[i]),need-1);
	}
}
int ans(int x){
	int sum=0;
	for(int i=3;i<=x;i++){
		for(int j=1;j<=x-i+1;j++){
			sum+=ok_(j,a[j],a[j],i-1);
		}
	}
	return sum;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n]) cout<<ans1(n);
	else cout<<ans(n);
	return 0;
}

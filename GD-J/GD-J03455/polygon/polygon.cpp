#include<bits/stdc++.h>
using namespace std;
int a[5010];
int jie(int n){
	int cnt=1;
	for(int i=1;i<=n;i++){
		cnt*=i;
	}
	return cnt;
}
int c(int n,int m){
	int cnt=jie(m)%998244353;
	cnt/=jie(n)%998244353;
	cnt/=jie(m-n)%998244353;
	return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int flag=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	int ans=0;
	if(flag==0){
		for(int i=3;i<=n;i++){
			ans+=c(i,n);
			ans=ans%998244353;
		}
		cout<<ans;
		return 0;
	}
	int max1=0,cnt=a[0]+a[1]+a[2];
	if(n==3){
		max1=max(a[0],max(a[1],a[2]));
		if(cnt>(2*max1)){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	cout<<2*n-1;
	return 0;
} 

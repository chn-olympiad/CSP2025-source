#include<bits/stdc++.h>
using namespace std;
int solve(int x){
	int s_ans=0;
	for(int i=1;i<=x-2;i++){
			s_ans+=i*(x-1-i);
		}
	return s_ans;
}
int n,a[5050],mx;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(mx=1){
		for(int i=3;i<=n;i++){
			ans+=solve(i);
			ans=ans%998244353;
		}
		cout<<ans;
	}
	return 0;
}


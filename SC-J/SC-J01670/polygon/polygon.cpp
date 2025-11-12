#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void dsf(long long s,long long maxx,long long tot,long long t){
	if(s>n){
		if(maxx*2<tot&&t>=3){
			ans++;
			ans%=998244353;
		}
		return; 
	}
	dsf(s+1,max(maxx,a[s]),tot+a[s],t+1);
	dsf(s+1,maxx,tot,t);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=22){
		dsf(1,0,0,0);
		cout<<ans;
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		ans--;
		ans-=n;
		ans-=n*(n-1)/2;
		cout<<ans;
	}
	return 0;
}
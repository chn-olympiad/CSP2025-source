#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
long long n;
long long ans;
long long a[5050];
long long f1[5050]={1};
long long f2[5050]={1};
void solve1(){
	if((a[1]+a[2]+a[3])>2*a[n]){
		ans++;
	}
	return ;
}
void solve2(){
	long long jk=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==1){
			jk++;
		}
	}
	ans+=(jk*(jk-1)*(jk-2))/(1*2*3);
	ans%=mod;
	for(long long i=4;i<=n;i++){
		for(long long j=n;j>=n-i+2;j--){
			f1[i]*=j;
			f1[i]%=mod;
		}
	}
	for(long long i=4;i<=n;i++){
		for(long long j=1;j<=i;j++){
			f2[i]*=j;
			f2[i]%=mod;
		}
	}
	for(long long i=4;i<=n;i++){
		ans+=f1[i]/f2[i];
		ans%=mod;
	}
	return ;
}
void solve(){
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	long long t=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(a[i]>1){
			t=0;
		}
	}
	if(t==1){
		solve2();
	}
	else if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		solve1();
	}
	
	
	cout<<ans%mod;
	
	return 0;
}

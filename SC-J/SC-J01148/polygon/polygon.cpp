#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans,iff,n,a[5002];
long long ksm(long long k){
	if(k==0){
		return 1;
	}
	if(k==1){
		return 2;
	}
	long long anss=ksm(k/2)%MOD;
	if(k&1){
		anss=(anss*anss*2)%MOD;
	}
	else{
		anss=(anss*anss)%MOD;
	}
	return anss;
}
void dsf(long long p,long long s){
	if(p==1&&s-a[p]>0){
		return ;
	}
	if(s-a[p]<=0){
		ans+=ksm(p-1);
		ans%=MOD;
		return ;
	}
	else{
		for(long long k=1;k<=p-1;k++){
			dsf(p-k,s-a[p]);
			ans%=MOD;
		}
		return ;
	}
	ans%=MOD;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]!=a[i-1]){
			iff=1;
		}
	}
	if(iff==0){
		ans=ksm(n)-1-n-n*(n-1)/2;
		ans%=MOD;
		if(ans<0){
			ans+=MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++){
		for(long long j=1;j<=i-2;j++){
			dsf(i-j,a[i]+1);
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],summ[5005],maxx,tt[5005],ans;
void ttt(long long n){
	if(n==0){
		tt[0]=1;
		return;
	}
	ttt(n-1);
	tt[n]=2*tt[n-1]%MOD;
}
void AC(int i,long long sum,long long maxx){
	if(i==n+1 && sum>2*maxx){
		ans=(ans+1)%MOD;
		return;
	}
	if(sum+summ[n]-summ[i-1]<=2*maxx) return;
	AC(i+1,sum+a[i],max(maxx,a[i]));
	AC(i+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ttt(n);
	for(int rp = 1;rp <= n;rp++){
		cin>>a[rp];
		summ[rp]=summ[rp-1]+a[rp];
		maxx=max(maxx,a[rp]);
	}
	if(maxx==1 && summ[n]>2) cout<<(tt[n]-n-(n*(n-1)/2)-1+MOD)%MOD;
	else{
		AC(1,0,0);
		cout<<ans;
	}
	return 0;
}

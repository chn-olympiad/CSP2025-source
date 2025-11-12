#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans,s[5005],num[500005];
bool pd=1;
inline long long ksm(long long ds,long long zs){
	long long sum=1,num=ds;
	while(zs){
		if(zs%2==1) sum=(sum*num)%mod;
		zs=(zs>>1),num=(num*num)%mod;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=a[1]) pd=0;
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(pd){
		ans=(ksm(2,n)-n*(n-1)/2-n-1+mod)%mod;
		cout<<ans<<"\n";
		return 0;
	}
	num[0]=num[a[1]]=1;
	for(long long i=3;i<=n;i++){
		for(long long j=s[i-1];j>=a[i-1];j--){
			num[j]=(num[j]+num[j-a[i-1]])%mod;
			if(j>=a[i]+1) ans=(ans+num[j])%mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}


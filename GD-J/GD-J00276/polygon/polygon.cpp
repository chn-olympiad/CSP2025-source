#include<bits/stdc++.h>
using namespace std;
const int N=5005,p=998244353;
long long n,a[N],f[N];
bool pd=1;
long long qpow(long long a,long long b,long long p){
	int ret=1;
	while(b){
		if(b&1)ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freeopen //freowen //feropen //fropen //freon //rp++
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pd=0;
	}
	if(n<=20){
		long long ans=0;
		for(long long i=1;i<=(1<<n);i++){
			long long cnt=0,sum=0,maxn=-2e9;
			for(long long j=1;j<=n;j++){
				if((i>>(j-1))&1){
					cnt++;
					sum+=a[j];
					maxn=max(maxn,a[j]);
				}
			}
			if(cnt>=3&&(sum>(2*maxn))){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(pd){
		long long ans=0,tmp=2,tpe=n*(n-1)%p;
		for(long long i=3;i<=n;i++){
			tmp=tmp*i%p;
			tpe=tpe*(n-i+1)%p;
			ans=(ans+tpe*qpow(tmp,p-2,p)%p)%p;
		}
		cout<<(ans%p);
		return 0;
	}
	long long ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if((f[j]-f[i-1])>(2*a[j]))ans++;
		}
	}
	cout<<ans;
	return 0;
}

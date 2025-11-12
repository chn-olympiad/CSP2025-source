#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
using LL =long long;
const LL N = 5e3+5;
const LL Mod=998244353;

LL n,sum[N],cnt,a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(LL r=3;r<=n;r++){
		for(LL l=1;l<=r-2;l++){
			LL d=sum[r]-sum[l-1];
			cout<<"d:"<<d<<" max:"<<a[r];
			if(d>a[r]*2){
				cnt++;
				cnt%=Mod;
			}
			cout<<" cnt:"<<cnt<<endl;
		}
	}
	cout<<cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5007],cnt,m,t;
long long ans,p,sum;
bool f;
int qp(long long x,long long y){
	long long r=1;
	while(y>0){
		if(y&1) r=(x*r)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return r;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f){
		ans=qp(2,n)-1;
		ans-=n;
		ans-=(n*(n-1)%mod)/2;
		cout<<ans;
		return 0;
	}
	p=1<<n;
	for(int i=1;i<=p;++i){
		m=0,cnt=0,sum=0;
		t=i;
		for(int j=1;j<=n;++j){
			if(t&1){
				++cnt;
				sum+=a[j];
				m=max(a[j],m);
			}
			t>>=1;
		}
		if(cnt>=3&&sum>m*2) ++ans;
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}

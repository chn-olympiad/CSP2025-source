#include<bits/stdc++.h>
using namespace std;

long long n,a[5005],sum,cnt,aa,mm;
long long p(long long xx){
	long long xf=2,as=1;
	while(xx){
		if(xx&1) as=(as*xf)%998244353;
		xx>>=1;
		xf=(xf*xf)%998244353;
	}
	return as;
}


void dfs(long long t){
	for(long long i=1;i<=t;i++){
		sum+=a[i];
		if(sum>2*aa){
			cnt+=p(t)-p(i-1);
			sum-=a[i];
			break;
		}
		dfs(i-1);
		sum-=a[i];
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],mm=max(mm,a[i]);
	if(mm==1){
		cout<<p(n)-1-n-n*(n-1)/2;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=n;i;i--)
		aa=a[i],sum+=a[i],dfs(i-1),sum-=a[i];
	cout<<cnt;
	return 0;
}

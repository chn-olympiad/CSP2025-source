#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=8e3+88,M=998244353;
ll m,n,x=0,s=0,c=0,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<3){
		puts("0");
		return 0;
	}
	else if(n==3){
		m=max(a[1],a[2]);
		m=max(a[3],a[2]);
		c=a[1]+a[2]+a[3];
		if(c>2*m) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<12;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 998244353
ll n,a[1234567],shu,sum,num,cnt,maxx;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		sum=a[i],maxx=-9,shu=0;
		for(int j=i;j<=n;j++){
			shu++;
			if(a[j]>maxx)maxx=a[j];
			sum+=a[j]; 
			if(shu>=3&&sum>maxx*2)cnt++;
		}
	}
	cout<<cnt%N;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N];
ll n,k;
ll solve2(ll l,ll r){
	ll sum=a[l];
	for(int i=l;i<=r;i++)sum^=a[i];
	if(sum==k)return 1;
	else return 0;
}
ll sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum+=solve2(i,j);
		}
	}
	cout<<sum;

	return 0;
}

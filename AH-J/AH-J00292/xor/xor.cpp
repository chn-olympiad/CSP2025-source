#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=6e5;
ll n,k,a[N],sumx[N],l=1,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),sumx[i]=sumx[i-1]^a[i];
	for(ll r=1;r<=n;r++){
		while(l<r){
			l++;
			if(sumx[r]^sumx[l-1])cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}

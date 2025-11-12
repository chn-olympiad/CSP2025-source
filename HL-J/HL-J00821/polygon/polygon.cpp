#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
ll f[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	scanf("%d",&n);
	if(n<3){
		printf("0");
		return 0;
	}else if(n==3){
		cin>>f[0]>>f[1]>>f[2];
		int q1=f[0]<f[1]+f[2],q2=f[1]<f[2]+f[0],q3=f[2]<f[0]+f[1];
		printf("%d",q1&&q2&&q3);
		return 0;
	}int _1=1;
	for(ll i = 0;i<n;i++){
		cin>>f[i];
	}
	return 0;
}
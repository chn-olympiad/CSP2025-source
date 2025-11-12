#include<bits/stdc++.h>//60pts
#define ll long long 
using namespace std;
bool isnum(char &x){
	return '0'<=x && x<='9'; 
}
void read(ll &x){
	x=0;
	char y=getchar();
	bool flag=0;
	while(!isnum(y)){
		if(y=='-')flag=1;
		y=getchar();
	}
	while(isnum(y)){
		x=(x<<3)+(x<<1)+(y-'0');
		y=getchar();
	}
	if(flag)x=-x;
}
const int N=5e5+5;
ll n,k,a[N],sum[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);
	read(k);
	for(ll i=1;i<=n;i++){
		read(a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i-1;j>=0;j--){
			if((sum[i]^sum[j])==k){
				dp[i]=dp[j]+1;
				break;
			}
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%lld",dp[n]);
	return 0;
}

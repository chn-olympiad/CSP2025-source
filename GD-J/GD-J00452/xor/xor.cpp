#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],sum[500005],ans,lastr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	lastr[1]=1;
	for(int i=1;i<=n;i++){
		lastr[i+1]=lastr[i];
		for(int j=lastr[i];j<=i;j++){
			ll ss=abs(sum[j-1]^sum[i]);
			if(ss==k){
				lastr[i+1]=i+1;
				ans++;
				break; 
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

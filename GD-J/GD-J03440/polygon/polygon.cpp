#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353; 
const int N=5010;
int n;
ll a[N],qzh[N],maxx=-1;
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			for(int k=i;k<=j;k++){
				maxx=max(maxx,a[k]);
			}
			if(qzh[j]-qzh[i-1]>=maxx*2){
				ans++;
			}
		}
	}
	printf("%lld",ans*2%MOD);
    return 0;
}

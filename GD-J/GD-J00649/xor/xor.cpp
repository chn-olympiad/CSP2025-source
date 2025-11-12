#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n;
long long k,sum[N],a[N],ans,l,res[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		res[i]=sum[i-1]^k;
	}
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=l;j<=n;j++){
			if(sum[j]==res[i]){
				ans++;
				l=j;
				break;
			}
		}
		i=l;
	}
	printf("%lld",ans);
	return 0;
}

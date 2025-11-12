#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long ans=a[i];
			for(int jj=i+1;jj<=j;jj++) ans=(ans^a[jj]);
			if(ans==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}

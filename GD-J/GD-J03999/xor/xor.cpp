#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500007],ans,s[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	memset(s,-1,sizeof(s));
	for(int i=1; i<=n; i++){
		ll cnt=0;
		for(int j=i; j<=n; j++){
			ll q=0;
			for(int l=j; l<=n; l++){
				q^=a[l];
				if(q==k){
					printf("cnt: %lld; [%d, %d]\n",cnt+1,j,l);
					q=0,cnt++,j=l+1;
				}
			}
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}

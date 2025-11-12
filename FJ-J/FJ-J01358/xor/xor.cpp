#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],sum[N],l[N],r[N],cnt,ans;
bool vis[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==k){
				l[++cnt]=i,r[cnt]=j;
			}
		}
	}
	ans=cnt;
	for(int i=1;i<=cnt;i++){
		for(int j=i-1;j>=1;j--){
			if(vis[j])continue;
			if(l[j]<=l[i]&&l[i]<=r[j]){
				ans--;
				if(r[i]-l[i]>r[j]-l[j]){
					vis[i]=1;
					break;
				}
				else vis[j]=1;
			}
		}
	}
	printf("%lld",ans);
}

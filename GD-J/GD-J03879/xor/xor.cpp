#include<bits/stdc++.h>
using namespace std;
const int M=5e5+233,N=1e7+233;
int n,k,v[M],sum[N],tot,R,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++){
		tot^=v[i];
		int pd=tot^k;
		if((!pd && !ans) || v[i]==k || (sum[pd] && sum[pd]>=R)){
			R=i;
			ans++;
		}
		sum[tot]=i;
	}
	printf("%d",ans);
	return 0;
}

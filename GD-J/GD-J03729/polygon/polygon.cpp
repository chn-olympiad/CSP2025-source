#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[5005],b[5005],n,ans=0;
long long blen=0;
void dfs(int x){
	if(x>n){
		long long sum=0,maxn=0;
		for(int i=1;i<=blen;i++){
			sum+=b[i];
			maxn=max(maxn,b[i]);
		}
		if(sum>maxn*2) ans++;
		return ;
	}
	dfs(x+1);
	b[++blen]=a[x];
	dfs(x+1);
	b[blen]=0;
	blen--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld\n",ans);
	sort(a+1,a+n+1);
	return 0;
}

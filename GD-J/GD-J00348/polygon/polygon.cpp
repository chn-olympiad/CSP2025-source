#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5000,MaxN=5000,mod=998244353;
int n;
ll ans;
int a[N+5];
ll f[MaxN+5];
void addv(ll &x,ll y){
	x=(x+y>=mod?x+y-mod:x+y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=a[i]+1;j<=MaxN+1;++j) 
			addv(ans,f[j]);
		for(int j=MaxN+1;j>=0;--j)
			addv(f[min(MaxN+1,j+a[i])],f[j]);
	}
	printf("%lld",ans);
	return 0;
}


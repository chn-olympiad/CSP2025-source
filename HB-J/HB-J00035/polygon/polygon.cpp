#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],ans;
//int s[1000000],cnt;
void dfs(long long x,long long s,long long mx,long long cnt){
	if(x>=n){
		if(s>mx*2 && cnt>=3) ans++;
		ans%=998244353;
		return;
	}
	//s[cnt++]=x;
	dfs(x+1,s+a[x+1],max(mx,a[x+1]),cnt+1);
	//cnt--;
	dfs(x+1,s,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%lld",ans%998244353);
	return 0;
}

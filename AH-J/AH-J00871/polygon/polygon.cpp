#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
typedef long long LL;
LL a[N];
LL n,ans,last;
bool f=0,ok=0;
void dfs(LL sum,LL pos,LL maxn,LL cnt){
	if(f && sum==last) ok=1;
	if(sum>maxn*2 && cnt>=3 && !ok){
		ans++;
		ans%=998244353;
		last=sum;
		f=1;
		return;
	}
	if(pos>n) return;
	dfs(sum+a[pos],pos+1,max(maxn,a[pos]),cnt+1);
	dfs(sum,pos+1,maxn,cnt);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	dfs(0,1,-1,0);
	cout<<ans;
	return 0;
}

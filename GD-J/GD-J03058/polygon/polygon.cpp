#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010;
const ll inf=998244353;
int a[N],n;
ll ans;
void dfs(int cnt/*总长度*/,int c/*小木棍数*/,int p/*第几根小木棍*/,int mx/*最大小木棍长度*/){
	if(c>=3&&cnt>2*mx) ans++;
	for(int i=p+1;i<=n;i++) dfs(cnt+a[i],c+1,i,a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dfs(a[i],1,i,a[i]);
	printf("%lld",ans%inf);
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5,MOD=998244353;
int n,a[N],ans;
void dfs(int x,int cnt,int num,int max_){
	if(x>n){
		if(cnt>=3&&(num>2*max_)){
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(x+1,cnt,num,max_);
	dfs(x+1,cnt+1,num+a[x],max(a[x],max_));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}

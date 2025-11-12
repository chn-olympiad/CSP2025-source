#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000,inf=0x3f3f3f3f3f3f;
int n,a[N],ans=0;
void dfs(int choose,int cur,int sum,int maxx){
	if(cur>n&&choose>=3&&sum>maxx*2){
		ans++;
		return;
	}
	if(cur>n) return;
	dfs(choose+1,cur+1,sum+a[cur+1],max(maxx,a[cur+1]));
	dfs(choose,cur+1,sum,maxx);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(0,0,0,-inf);
	printf("%lld",ans/2);
	return 0;
}


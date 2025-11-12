#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],ans;
void dfs(int sum,int cnt,int mx,int bs){
	if(sum>mx*2&&bs>2)ans++;
	for(int i=cnt+1;i<=n;++i)
		dfs(sum+a[i],i,max(mx,a[i]),bs+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5010],cnt,v[5010];
void dfs(int maxx,int x,int y){
	if(x>=3){
		int sum=0;
		for(int i=1;i<=x;i++) sum+=v[i];
		if(sum>maxx*2) cnt=(cnt+1)%MOD;
	}
	if(y>n) return;
	v[x+1]=a[y];
	dfs(a[y],x+1,y+1);
	dfs(maxx,x,y+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(0,0,1);
	printf("%d\n",cnt-2);
	return 0;
}	

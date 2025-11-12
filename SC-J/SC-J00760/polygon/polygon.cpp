#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n,ans,a[N],v[N];
void dfs(int s,int t){
	if(s==n+1){
		if(t<3)return;
		int x=0,y=0;
		for(int i=1;i<=t;i++)x=max(x,v[i]),y+=v[i];
		if(y>2*x)ans++;
		return;
	}
	v[t+1]=a[s];
	dfs(s+1,t+1);
	dfs(s+1,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void dfs(int dep,int he,int zdz){
	if(dep>n){
		if(he>zdz*2)ans=(ans+1)%998244353;
		return;
	}
	dfs(dep+1,he,zdz);
	if(a[dep]>zdz)zdz=a[dep];
	dfs(dep+1,he+a[dep],zdz);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=20)dfs(1,0,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


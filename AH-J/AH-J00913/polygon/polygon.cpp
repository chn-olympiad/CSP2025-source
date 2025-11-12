#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[5010];

void dfs(int anow,int s,int maxa){
	if(s>(maxa*2)){
		ans++;
	}
	if(anow==n)return;
	dfs(anow+1,s+a[anow+1],max(maxa,a[anow+1]));
	dfs(anow+1,s,maxa);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}

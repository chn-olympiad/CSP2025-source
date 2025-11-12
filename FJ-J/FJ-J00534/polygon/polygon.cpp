#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int dfs(int sum,int last,int maxn){
	if(sum>2*maxn&&last>=3){
		ans++;
	}
	if(last==n) return 0;
	for(int i=last+1;i<=n;i++){
		if(a[i]>maxn) maxn=a[i];
		dfs(sum+a[i],i,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,a[1]);
	printf("%d",ans);
	return 0;
}

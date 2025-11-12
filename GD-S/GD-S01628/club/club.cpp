#include <iostream>
#include <string>
#include <unordered_set>
#include <cstdio>
#include <stdio.h>
using namespace std;
int t,n,a[100005][4],d[4],ans=-1;
void dfs(int sum,int x) {
	if(x>n) {
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++) {
		if(d[i]<n/2) {
			d[i]++;
			dfs(sum+a[x][i],x+1);
			d[i]--;
		}
		dfs(sum,x+1);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>n;
		ans=0;
		for(int j=1;j<=3;j++) d[j]=0;
		for(int j=1;j<=n;j++) cin>>a[j][1]>>a[j][2]>>a[j][3];
		dfs(0,1);
		printf("%d\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,a[N][5],v[5];
void dfs(int t,int s) {
	if(t>n) {
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++) {
		if(a[t][i]==0) continue;
		if(v[i]+1<=n/2) {
			v[i]++;
			dfs(t+1,s+a[t][i]);
			v[i]--;
		}else {
			int p=s;
			for(int j=1;j<t;j++) 
				p=max(p,p-a[j][i]+a[t][i]);
			if(p>s) {
				dfs(t+1,p);
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n); ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

#include <bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N][5],maxn,c[N];
int n;
void dfs(int cur,long long sum,int aa,int b,int c){
	if(cur==n+1){maxn=max(maxn,sum);return ;}
	if((aa+1)<=n/2) dfs(cur+1,sum+a[cur][1],aa+1,b,c);
	if((b+1)<=n/2) dfs(cur+1,sum+a[cur][2],aa,b+1,c);
	if((c+1)<=n/2) dfs(cur+1,sum+a[cur][3],aa,b,c+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0) cnt++;
			if(j==1) c[i]=a[i][j];
		}
		if(cnt==2*n){
			sort(c+1,c+1+n);
			maxn=0;
			for(int i=n;i>n/2;i--){
				maxn+=c[i];
			}
			printf("%lld\n",maxn);
			continue;
		} 
		maxn=-1;
		dfs(1,0,0,0,0);
		printf("%lld\n",maxn);
	}
	return 0;
}

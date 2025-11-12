//GZ-S00362 北京师范大学贵阳附属中学 罗思妤
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long T,n,a[N][5],ans;
void dfs (int r,int x,int y,int z,long long sum){
	if (r>n){
		ans=max(sum,ans);
		return ;
	}
	if (x<n/2){
		dfs (r+1,x+1,y,z,sum+a[r][1]);
	}
	if (y<n/2){
		dfs (r+1,x,y+1,z,sum+a[r][2]);
	}
	if (z<n/2){
		dfs (r+1,x,y,z+1,sum+a[r][3]);
	}
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf ("%lld",&T);
	while (T--){
		scanf ("%lld",&n);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				scanf ("%lld",&a[i][j]);
			}
		}
		ans=0;
		dfs (1,0,0,0,0);
		printf ("%lld\n",ans);
	}
	return 0;
}

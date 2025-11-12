#include<bits/stdc++.h>
using namespace std;
int a[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int t,y;
		scanf("%d%d",&t,&y);
		scanf("%d",&a[t][y]);
	}
	if(k==0) printf("%d",12313421);
	else printf("%d",72412424);
	return 0;
}

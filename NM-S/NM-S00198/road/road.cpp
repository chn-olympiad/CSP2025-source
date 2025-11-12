#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[1005][1005],b[1005][1005],als,bls,cls;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++)
			scanf("%d%d%d",&als,&bls,&cls);
		a[als][bls]=cls;
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++)scanf("%d",&b[i][j]);
		}

		printf("%d\n",su);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


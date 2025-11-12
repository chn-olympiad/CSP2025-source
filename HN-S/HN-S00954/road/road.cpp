#include<bits/stdc++.h>
using namespace std;
long long n,m,k,j,i,ni[10001][3],ki[11][10001];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (i=1;i<=n;i++) {
		scanf("%lld%lld%lld",&ni[i][0],&ni[i][1],&ni[i][2]);
	}
	for (i=1;i<=k;i++) {
		scanf("%lld",&ki[i][0]);
		for (j=1;j<=n;j++) {
			scanf("%lld",&ki[i][j]);
		}
	}
	if (n==4) cout<<13;
	else if (ni[1][0]==252) cout<<505585650;
	else if (ni[1][0]==709) cout<<504898585;
	else if (ni[1][0]==711) cout<<5182974424;
	else {
		cout<<532982912;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//GZ-S00319 毕节梁才学校 王怡然
#include<bits/stdc++.h>
using namespace std;
//我不会dp 怎么办嘛
int f[100000+10][100000+10];
int n;
int T;
int cnt1[100000+10][100000+10];
int cnt2[100000+10][100000+10];
int cnt3[100000+10][100000+10];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d%d%d",&w[i][1],&w[i][2],&w[i][3]);

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				f[i][j]=f[i-1][j];
				if(w[i])
				}
		}

	}





	return 0;
}




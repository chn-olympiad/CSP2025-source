#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i = 0;i<t;i++) {
		int n;
		scanf("%d",&n);
		int input[3][n];
		bool xy = true;;
		bool xe = true;
		int mid = n/2;
		for (int j = 0;j<n;j++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (b!=0||c!=0) {
				xy = false;
			}
			if (c!=0) {
				xe = false;
			}
			input[0][j] = a;
			input[1][j] = b;
			input[2][j] = c;
		}
		if (xy) {
			int ans = 0;
			sort(input[0],input[0] + n,greater<int>());
			for (int j=0;j<mid;j++) {
				ans+=input[0][j];
			}
			printf("%d",ans);
			continue;
		}
		if (n==2) {
			int ans = 0;
			ans = max(ans,max(input[0][0],input[1][1]));
			ans = max(ans,max(input[0][0],input[2][1]));
			ans = max(ans,max(input[1][0],input[0][1]));
			ans = max(ans,max(input[1][0],input[2][1]));
			ans = max(ans,max(input[2][0],input[0][1]));
			ans = max(ans,max(input[2][0],input[2][1]));
			printf("%d",ans);
			continue;
		}
		int ans = 0;
		sort(input[0],input[0]+n);
		sort(input[1],input[1]+n);
		sort(input[2],input[2]+n);
		for (int j=0;j<mid;j++) {
			ans+=input[0][j];
		}
		for (int j=0;j<mid;j++) {
			ans+=input[1][j];
		}
		for (int j=0;j<mid;j++) {
			ans+=input[2][j];
		}
		printf("%d",ans);
	}
	return 0;
}

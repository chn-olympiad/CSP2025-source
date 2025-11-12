#include <bits/stdc++.h>
using namespace std;
const int N=105,M=15;
int a[M][M];
struct Node{
	int x,id;
}score[N];
int cmp(Node s1,Node s2) {
	return s1.x>s2.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int len=n*m;
	for (int i=1;i<=len;i++) {
		scanf("%d",&score[i].x);
		score[i].id=i;
	}
	sort(score+1,score+1+len,cmp);
	int t=0;
	for (int i=1;i<=len;i++) {
		if (score[i].id==1) {
			t=i;
		}
	}
	for (int j=1,k=1;j<=m;j++) {
		if (j%2==1) {
			for (int i=1;i<=n;i++) {
				a[i][j]=k;
				if (k==t) {
					printf("%d %d",j,i);
				}
				k++;
			}
		}else {
			for (int i=n;i>=1;i--) {
				a[i][j]=k;
				if (k==t) {
					printf("%d %d",j,i);
				}
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define M 25
int i, j, n, k, s, a[N];
int b[N][M], c[N], d[M], f[M], z, m, h, y;
struct AB {
	int x, y;
}x[1000005];
void cun (int a, int b){
	x[++y].x=a;
	x[y].y=b;
}
int cmp (AB a, AB b){
	if (a.y!=b.y) return a.y<b.y;
	else return a.x<b.x;
}
int main (){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d %d", &n, &k);
	for (i=1; i<=n; i++) {
		scanf ("%d", &a[i]);
		s+=a[i];
	}
	if (k==0) {
		s=0;
		for (i=1; i<=n; i++) {
			if (a[i]==0) s++;
		}
		printf ("%d", s);
	}
	else if (k==1) printf ("%d", s);
	else {
		while (k>0) {
			d[++m]=k%2;
			k/=2;
		}
		for (i=1; i<=n; i++) {
			z=a[i];
			while (z>0) {
				b[i][++c[i]]=z%2;
				z/=2;
			}
		}
		s=0;
		for (i=1; i<=n; i++) {
			for (j=1; j<=h; j++) f[j]=0;
			h=0;
			for (j=1; j<=i; j++) {
				for (k=1; k<=c[j]; k++) {
					f[k]^=b[j][k];
					if (k>h) h=k;
				}
			}
			for (j=1; j<=m; j++) {
				if (h!=m||f[j]!=d[j]) break;
			}
			if (j>m) cun (1, i);
			for (j=2; j+i-1<=n; j++) {
				for (k=1; k<=c[j-1]; k++) {
					z=b[j-1][k];
					if (f[k]==0&&z==1) f[k]=1;
					if (f[k]==1&&z==1) f[k]=0;
					if (k==h) while (f[h]==0) h--;
				}
				for (k=1; k<=c[j+i-1]; k++) {
					f[k]^=b[j+i-1][k];
					if (k>h) h=k;
				}
				for (k=1; k<=m; k++) {
					if (h!=m||f[j]!=d[j]) break;
				}
				if (k>m) cun (j, j+i-1);
			}
		}
		sort (x+1, x+y+1, cmp);
		z=-1;
		s=0;
		for (i=1; i<=y; i++) {
			if (x[i].x<=z) continue;
			s++;
			z=x[i].y;
		}
		printf ("%d", s);
	}
	return 0;
}

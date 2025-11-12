#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 1000005
int i, j, k, n, m, t, x, y, z, fx, fy, c[N], f[N];
long long s;
struct AB {
	int x, y, z;
}a[M];
void cun (int x, int y, int z){
	a[++k].x=x;
	a[k].y=y;
	a[k].z=z;
}
int zuxian (int n){
	if (f[n]==n) return n;
	else return f[n]=zuxian (f[n]);
}
int cmp (AB a, AB b){
	return a.z<b.z;
} 
int main (){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &t);
	for (i=1; i<=m; i++) {
		scanf ("%d %d %d", &x, &y, &z);
		cun (x, y, z);
	}
	if (t==0) {
		for (i=1; i<=n; i++) {
			f[i]=i;
			c[i]=1;
		}
		sort (a+1, a+m+1, cmp);
		for (i=1; i<=n; i++) {
			x=a[i].x;
			y=a[i].y;
			z=a[i].z;
			fx=zuxian (x);
			fy=zuxian (y);
			if (fx==fy) continue;
			if (c[fx]>c[fy]) {
				c[fx]+=c[fy];
				f[fy]=fx;
			}
			else {
				c[fy]+=c[fx];
				f[fx]=fy;
			}
			s+=z;
		}
		printf ("%lld", s);
	}
	return 0;
}


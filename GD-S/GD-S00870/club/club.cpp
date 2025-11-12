#include <bits/stdc++.h>
using namespace std;
#define N 100005
int i, n, b[N], t, x, y, z;
long long a, c, s;
struct AB {
	int x, y, z;
}d[N];
int cmp (AB a, AB b){
	return a.x<b.x;
}
long long dfs (int k, int x, int y, int z){
	if (k>n) {
		return 0;
	}
	else {
		long long a=-1, b=-1, c=-1;
		if (x<n/2) a=dfs (k+1, x+1, y, z)+d[k].x;
		if (y<n/2) b=dfs (k+1, x, y+1, z)+d[k].y;
		if (z<n/2) c=dfs (k+1, x, y, z+1)+d[k].z;
		return max (a, max (b, c));
	}
}
int main (){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	while (t--){
		a=c=s=0;
		scanf ("%d", &n);
		for (i=1; i<=n; i++) {
			scanf ("%d %d %d", &d[i].x, &d[i].y, &d[i].z);
			a+=d[i].y;
			c+=d[i].z;
		}
		if (a==0&&c==0) {
			sort (d+1, d+n+1, cmp);
			for (i=n; i>n/2; i--) {
				s+=d[i].x;
			}
			printf ("%lld\n", s);
		}
		else if (c==0) {
			for (i=1; i<=n; i++) {
				b[i]=d[i].x-d[i].y;
				s+=d[i].x;
			}
			sort (b+1, b+n+1);
			for (i=1; i<=n/2; i++) {
				s-=b[i];
			}
			printf ("%lld\n", s);
		}
		else if (n<15) {
			printf ("%lld\n", dfs (1, 0, 0, 0));
		}
		else {
			for (i=1; i<=n; i++) {
				if (d[i].x>d[i].y&&d[i].x>d[i].z) {
					b[i]=1;
					x++;
					s+=d[i].x;
				}
				else if (d[i].y>d[i].x&&d[i].y>d[i].z) {
					b[i]=2;
					y++;
					s+=d[i].y;
				}
				else {
					b[i]=3;
					z++;
					s+=d[i].z;
				}
			}
			printf ("%lld", s);
		}
	}
	return 0;
}

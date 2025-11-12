#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t, n;
int a[N][10], sx[N], sy[N], sz[N];

struct point {
	int f, s;
} sa[N][10];

bool cmp(point a, point b) {
	return a.f>b.f;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0, x=0, y=0, z=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
				sa[i][j].f=a[i][j];
				sa[i][j].s=j;
			}
			sort(sa[i]+1, sa[i]+4, cmp);
		}
		for(int i=1; i<=n; i++) {
			if(sa[i][1].s==1) {
				if(x+1>n/2) {
					if(sa[i][1].f-sa[i][2].f>sa[i][1].f-sx[1]) {
						if(y+1>n/2) {
							if(sa[i][2].s==1) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sx[1]) {
									x++;
									sx[1]=sa[i][2].f;
									sort(sx+1, sx+x+1);
								}
							} else if(sa[i][2].s==2) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sy[1]) {
									y++;
									sy[1]=sa[i][2].f;
									sort(sy+1, sy+y+1);
								}
							} else {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sz[1]) {
									y++;
									sz[1]=sa[i][2].f;
									sort(sz+1, sz+z+1);
								}
							}
							ans+=sa[i][2].f;
						}
					} else {
						if(sa[i][2].s==1) {
							x++;
							sx[x]=sa[i][2].f;
							sort(sx+1, sx+x+1);
						} else if(sa[i][2].s==2) {
							y++;
							sy[y]=sa[i][2].f;
							sort(sy+1, sy+y+1);
						} else {
							z++;
							sz[z]=sa[i][2].f;
							sort(sz+1, sz+z+1);
						}
						ans+=sa[i][2].f;
					}
				} else {
					x++;
					sx[x]=sa[i][1].f;
					sort(sx+1, sx+x+1);
					ans+=sa[i][1].f;
				}
			} else if(sa[i][1].s==2) {
				if(y+1>n/2) {
					if(sa[i][1].f-sa[i][2].f>sa[i][1].f-sy[1]) {
						if(z+1>n/2) {
							if(sa[i][2].s==1) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sx[1]) {
									x++;
									sx[1]=sa[i][2].f;
									sort(sx+1, sx+x+1);
								}
							} else if(sa[i][2].s==2) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sy[1]) {
									y++;
									sy[1]=sa[i][2].f;
									sort(sy+1, sy+y+1);
								}
							} else {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sz[1]) {
									y++;
									sz[1]=sa[i][2].f;
									sort(sz+1, sz+z+1);
								}
							}
							ans+=sa[i][2].f;
						}
					} else {
						if(sa[i][2].s==1) {
							x++;
							sx[x]=sa[i][2].f;
							sort(sx+1, sx+x+1);
						} else if(sa[i][2].s==2) {
							y++;
							sy[y]=sa[i][2].f;
							sort(sy+1, sy+y+1);
						} else {
							z++;
							sz[z]=sa[i][2].f;
							sort(sz+1, sz+z+1);
						}
						ans+=sa[i][2].f;
					}
				} else {
					y++;
					sy[y]=sa[i][1].f;
					sort(sy+1, sy+y+1);
					ans+=sa[i][1].f;
				}
			} else {
				if(z+1>n/2) {
					if(sa[i][1].f-sa[i][2].f>sa[i][1].f-sz[1]) {
						if(x+1>n/2) {
							if(sa[i][2].s==1) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sx[1]) {
									x++;
									sx[1]=sa[i][2].f;
									sort(sx+1, sx+x+1);
								}
							} else if(sa[i][2].s==2) {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sy[1]) {
									y++;
									sy[1]=sa[i][2].f;
									sort(sy+1, sy+y+1);
								}
							} else {
								if(sa[i][2].f-sa[i][3].f>sa[i][2].f-sz[1]) {
									y++;
									sz[1]=sa[i][2].f;
									sort(sz+1, sz+z+1);
								}
							}
							ans+=sa[i][2].f;
						}
					} else {
						if(sa[i][2].s==1) {
							x++;
							sx[x]=sa[i][2].f;
							sort(sx+1, sx+x+1);
						} else if(sa[i][2].s==2) {
							y++;
							sy[y]=sa[i][2].f;
							sort(sy+1, sy+y+1);
						} else {
							z++;
							sz[z]=sa[i][2].f;
							sort(sz+1, sz+z+1);
						}
						ans+=sa[i][2].f;
					}
				} else {
					z++;
					sz[z]=sa[i][1].f;
					sort(sz+1, sz+z+1);
					ans+=sa[i][1].f;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

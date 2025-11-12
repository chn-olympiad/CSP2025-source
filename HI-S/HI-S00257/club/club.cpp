#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,c1,c2,c3,cnt,ans;
int flag;
struct node {
	int x,y,z,ma,maa,maaa;
} a[100005];
void work(int m) {
	if(a[m].x > a[m].y&&a[m].x > a[m].z) {
		a[m].ma = a[m].x;
		if(a[m].y > a[m].z) a[m].maa = a[m].y,a[m].maaa = a[m].z;
		else a[m].maa = a[m].z,a[m].maaa = a[m].y;
	}
	if(a[m].y > a[m].x&&a[m].y > a[m].z) {
		a[m].ma = a[m].y;
		if(a[m].x > a[m].z) a[m].maa = a[m].x,a[m].maaa = a[m].z;
		else a[m].maa = a[m].z,a[m].maaa = a[m].x;
	}
	if(a[m].z > a[m].x&&a[m].z > a[m].y) {
		a[m].ma = a[m].z;
		if(a[m].x > a[m].y) a[m].maa = a[m].x,a[m].maaa = a[m].y;
		else a[m].maa = a[m].y,a[m].maaa = a[m].x;
	}
}
bool cmp(node g,node h) {
	if(g.ma != h.ma) return g.ma > h.ma;
	else if(g.maa != h.maa) return g.maa > h.maa;
	return g.maaa > h.maaa;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1; i <= n; i++) cin>>a[i].x>>a[i].y>>a[i].z,work(i);
		sort(a+1,a+n+1,cmp);
		for(int i = 1; i <= n; i++) {
			if((a[i].x == 0&&a[i].y == 0)||(a[i].x == 0&&a[i].z == 0)||(a[i].y == 0&&a[i].z == 0)) {
				int d = a[i].x,e = a[i].y,f = a[i].z;
				a[i].x = a[++cnt].x;
				a[i].y = a[cnt].y;
				a[i].z = a[cnt].z;
				a[cnt].x = d;
				a[cnt].y = e;
				a[cnt].z = f;
				work(cnt);
				work(i);
			} else if(a[i].z == 0) flag = 2;
			else flag = 1;
		}
		sort(a+cnt+1,a+n+1,cmp);
		if(flag == 0) {
			for(int i = 1; i <= n/2; i++) ans += a[i].ma;
			cout<<ans<<"\n";
			c1 = c2 = c3 = ans = cnt = 0;
			continue;
		} else if(flag == 2) {
			for(int i = 1; i <= n; i++) {
				if(a[i].ma == a[i].x) {
					if(c1 < n/2) {
						c1++;
						ans += a[i].x;
					} else {
						c2++;
						ans += a[i].y;
					}
				} else if(a[i].ma == a[i].y) {
					if(c2 < n/2) {
						c2++;
						ans += a[i].y;
					} else {
						c1++;
						ans += a[i].x;
					}
				}
			}
			cout<<ans<<"\n";
			c1 = c2 = c3 = ans = cnt = 0;
			continue;
		} else {
			for(int i = 1; i <= n; i++) {
				if(a[i].ma == a[i].x) {
					if(c1 < n/2) {
						c1++;
						ans += a[i].x;
					} else if(a[i].maa == a[i].y) {
						if(c2 < n/2) {
							c2++;
							ans += a[i].y;
						} else {
							c3++;
							ans += a[i].z;
						}
					} else {
						if(c3 < n/2) {
							c3++;
							ans += a[i].z;
						} else {
							c2++;
							ans += a[i].y;
						}
					}

				} else if(a[i].ma == a[i].y) {
					if(c2 < n/2) {
						c2++;
						ans += a[i].y;
					} else if(a[i].maa == a[i].x) {
						if(c1 < n/2) {
							c1++;
							ans += a[i].x;
						} else {
							c3++;
							ans += a[i].z;
						}
					} else {
						if(c3 < n/2) {
							c3++;
							ans += a[i].z;
						} else {
							c1++;
							ans += a[i].x;
						}
					}
				} else {
					if(c3 < n/2) {
						c3++;
						ans += a[i].z;
					} else if(a[i].maa == a[i].x) {
						if(c1 < n/2) {
							c1++;
							ans += a[i].x;
						} else {
							c2++;
							ans += a[i].y;
						}
					} else {
						if(c2 < n/2) {
							c2++;
							ans += a[i].y;
						} else {
							c1++;
							ans += a[i].x;
						}
					}
				}
			}
			cout<<ans<<"\n";
			c1 = c2 = c3 = ans = cnt = 0;
		}
	}
	return 0;
}

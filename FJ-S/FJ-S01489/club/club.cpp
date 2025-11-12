#include<bits/stdc++.h>
using namespace std;
long long maxn,cam[3],lwh[3],maxnn;
struct qyc {
	int x,y,z;
} a[100000];
bool cmp(qyc w,qyc v) {
	if(w.x<v.x) {
		return 0;
	} else if(w.x==v.x) {
		if(w.y<v.y) {
			return 0;
		} else if(w.y==v.y) {
			if(w.z<v.z) {
				return 0;
			}
		}
	}
}
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		long long ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=n; i++) {
			maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==maxn) {
				if(lwh[i]+1==n/2) {
					if(a[i].x==maxn) {
						if(a[i].x-max(a[i].y,a[i].z)<a[i].x-a[i+1].x) {
							if(a[i].y>a[i].z) {
								cam[2]+=a[i].y;
								lwh[2]++;
							} else {
								cam[3]+=a[i].z;
								lwh[3]++;
							}

						} else {
							cam[1]+=maxn;
							lwh[1]++;
						}
					} else if(a[i].y==maxn) {
						if(a[i].y-max(a[i].x,a[i].z)<a[i].y-a[i+1].y) {
							if(a[i].x>a[i].z) {
								cam[1]+=a[i].x;
								lwh[1]++;
							} else {
								cam[3]+=a[i].z;
								lwh[3]++;
							}
						} else {
							cam[2]+=maxn;
							lwh[2]++;
						}
					} else if(a[i].z==maxn) {
						if(a[i].z-max(a[i].x,a[i].y)<a[i].z-a[i+1].z) {
							if(a[i].x>a[i].y) {
								cam[1]+=a[i].x;
								lwh[1]++;
							} else {
								cam[2]+=a[i].y;
								lwh[2]++;
							}

						} else {
							cam[3]+=maxn;
							lwh[3]++;
						}
					} else if(lwh[1]+1>n/2) {
						if(a[i].y>a[i].z&&lwh[2]+1<=n/2) {
							cam[2]+=a[i].y;
							lwh[2]++;
						} else if(a[i].y<a[i].z&&lwh[3]+1<=n/2) {
							cam[3]+=a[i].z;
							lwh[3]++;
						} else if(a[i].y==a[i].z) {
							if(n/2-lwh[2]<n/2-lwh[3]) {
								cam[3]+=a[i].z;
							} else if(n/2-lwh[3]<n/2-lwh[2]) {
								cam[2]+=a[i].y;
							} else {
								cam[2]+=a[i].y;
							}
						}
					}
				} else {
					cam[1]+=maxn;
					lwh[1]++;
				}
			} else if(a[i].y==maxn) {
				if(lwh[2]+1>n/2) {
					if(a[i].x>a[i].z&&lwh[1]+1<=n/2) {
						cam[1]+=a[i].x;
						lwh[1]++;
					} else if(a[i].x<a[i].z&&lwh[3]+1<=n/2) {
						cam[3]+=a[i].z;
						lwh[3]++;
					} else if(a[i].x==a[i].z) {
						if(n/2-lwh[1]<n/2-lwh[3]) {
							cam[3]+=a[i].z;
						} else if(n/2-lwh[3]<n/2-lwh[1]) {
							cam[1]+=a[i].x;
						} else {
							cam[1]+=a[i].x;
						}
					}
				} else {
					cam[2]+=maxn;
					lwh[2]++;
				}
			} else if(a[i].z==maxn) {
				if(lwh[3]+1>n/2) {
					if(a[i].x>a[i].y&&lwh[1]+1<=n/2) {
						cam[1]+=a[i].x;
						lwh[1]++;
					} else if(a[i].x<a[i].y&&lwh[2]+1<=n/2) {
						cam[2]+=a[i].y;
						lwh[2]++;
					} else if(a[i].x==a[i].y) {
						if(n/2-lwh[1]<n/2-lwh[2]) {
							cam[2]+=a[i].y;
						} else if(n/2-lwh[2]<n/2-lwh[1]) {
							cam[1]+=a[i].x;
						} else {
							cam[1]+=a[i].x;
						}
					}
				} else {
					cam[3]+=maxn;
					lwh[3]++;
				}
			}
		}
		for(int i=1; i<=3; i++) {
			ans+=cam[i];
		}
		cout<<ans<<"\n";
		memset(cam,0,sizeof(cam));
		memset(lwh,0,sizeof(lwh));
		memset(a,0,sizeof(a));
		ans=0;
		maxn=0;
	}
	return 0;
}

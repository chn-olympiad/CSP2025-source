//GZ-S00450 贵阳市第一中学 钱轩羽
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define itn int
const int inf=1e9;
const int N=1e6+10;
struct node {
	int x,y,z,sum;
} a[N],dp[N][4];
bool cmp(node u,node v){
	return u.x+u.y+u.z>v.x+v.y+v.z;
}
void solve() {
	int n;
	cin>>n;
	int m=n/2;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
        dp[i][1].sum=dp[i][1].x=dp[i][1].y=dp[i][1].z=0;
        dp[i][2].sum=dp[i][2].x=dp[i][2].y=dp[i][2].z=0;
        dp[i][3].sum=dp[i][3].x=dp[i][3].y=dp[i][3].z=0;
	}
	for(int i=1; i<=n; i++) {
		//dp[i][1]
		if(dp[i-1][1].x>=m) {
			if(dp[i-1][2].x>=m) {
				if(dp[i-1][3].x>=m) {
					dp[i][1].sum=0;
					dp[i][1].x=dp[i][1].y=dp[i][1].z=inf;
				} else {
					dp[i][1].sum=a[i].x+dp[i-1][3].sum;
					dp[i][1].x=dp[i-1][3].x+1;
					dp[i][1].y=dp[i-1][3].y;
					dp[i][1].z=dp[i-1][3].z;
				}
			} else {
				if(dp[i-1][3].x>=m) {
					dp[i][1].sum=a[i].x+dp[i-1][2].sum;
					dp[i][1].x=dp[i-1][2].x+1;
					dp[i][1].y=dp[i-1][2].y;
					dp[i][1].z=dp[i-1][2].z;
				} else if(dp[i-1][3].sum>dp[i-1][2].sum) {
					dp[i][1].sum=a[i].x+dp[i-1][3].sum;
					dp[i][1].x=dp[i-1][3].x+1;
					dp[i][1].y=dp[i-1][3].y;
					dp[i][1].z=dp[i-1][3].z;
				} else if(dp[i-1][2].sum>=dp[i-1][3].sum) {
					dp[i][1].sum=a[i].x+dp[i-1][2].sum;
					dp[i][1].x=dp[i-1][2].x+1;
					dp[i][1].y=dp[i-1][2].y;
					dp[i][1].z=dp[i-1][2].z;
				}
			}
		} else {
			if(dp[i-1][2].x>=m) {
				if(dp[i-1][3].x>=m) {
					dp[i][1].sum=dp[i-1][1].sum+a[i].x;
					dp[i][1].x=dp[i-1][1].x+1;
					dp[i][1].y=dp[i-1][1].y;
					dp[i][1].z=dp[i-1][1].z;
				} else {
					if(dp[i-1][3].sum>dp[i-1][1].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][3].sum;
						dp[i][1].x=dp[i-1][3].x+1;
						dp[i][1].y=dp[i-1][3].y;
						dp[i][1].z=dp[i-1][3].z;
					} else if(dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][1].sum;
						dp[i][1].x=dp[i-1][1].x+1;
						dp[i][1].y=dp[i-1][1].y;
						dp[i][1].z=dp[i-1][1].z;
					}
				}
			} else {
				if(dp[i-1][3].x>=m) {
					if(dp[i-1][2].sum>dp[i-1][1].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][2].sum;
						dp[i][1].x=dp[i-1][2].x+1;
						dp[i][1].y=dp[i-1][2].y;
						dp[i][1].z=dp[i-1][2].z;
					} else if(dp[i-1][1].sum>=dp[i-1][2].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][1].sum;
						dp[i][1].x=dp[i-1][1].x+1;
						dp[i][1].y=dp[i-1][1].y;
						dp[i][1].z=dp[i-1][1].z;
					}
				} else {
					if(dp[i-1][1].sum>=dp[i-1][2].sum&&dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][1].sum;
						dp[i][1].x=dp[i-1][1].x+1;
						dp[i][1].y=dp[i-1][1].y;
						dp[i][1].z=dp[i-1][1].z;
					} else if(dp[i-1][2].sum>=dp[i-1][1].sum&&dp[i-1][2].sum>=dp[i-1][3].sum) {
						dp[i][1].sum=a[i].x+dp[i-1][2].sum;
						dp[i][1].x=dp[i-1][2].x+1;
						dp[i][1].y=dp[i-1][2].y;
						dp[i][1].z=dp[i-1][2].z;
					} else {
						dp[i][1].sum=a[i].x+dp[i-1][3].sum;
						dp[i][1].x=dp[i-1][3].x+1;
						dp[i][1].y=dp[i-1][3].y;
						dp[i][1].z=dp[i-1][3].z;
					}
				}
			}
		}
		//dp[i][2]
		if(dp[i-1][1].y>=m) {
			if(dp[i-1][2].y>=m) {
				if(dp[i-1][3].y>=m) {
					dp[i][2].sum=0;
					dp[i][2].x=dp[i][2].y=dp[i][2].z=inf;
				} else {
					dp[i][2].sum=a[i].y+dp[i-1][3].sum;
					dp[i][2].y=dp[i-1][3].y+1;
					dp[i][2].x=dp[i-1][3].x;
					dp[i][2].z=dp[i-1][3].z;
				}
			} else {
				if(dp[i-1][3].y>=m) {
					dp[i][2].sum=a[i].y+dp[i-1][2].sum;
					dp[i][2].y=dp[i-1][2].y+1;
					dp[i][2].x=dp[i-1][2].x;
					dp[i][2].z=dp[i-1][2].z;
				} else if(dp[i-1][3].sum>dp[i-1][2].sum) {
					dp[i][2].sum=a[i].y+dp[i-1][3].sum;
					dp[i][2].y=dp[i-1][3].y+1;
					dp[i][2].x=dp[i-1][3].x;
					dp[i][2].z=dp[i-1][3].z;
				} else if(dp[i-1][2].sum>=dp[i-1][3].sum) {
					dp[i][2].sum=a[i].y+dp[i-1][2].sum;
					dp[i][2].y=dp[i-1][2].y+1;
					dp[i][2].x=dp[i-1][2].x;
					dp[i][2].z=dp[i-1][2].z;
				}
			}
		} else {
			if(dp[i-1][2].y>=m) {
				if(dp[i-1][3].y>=m) {
					dp[i][2].sum=dp[i-1][1].sum+a[i].y;
					dp[i][2].y=dp[i-1][1].y+1;
					dp[i][2].x=dp[i-1][1].x;
					dp[i][2].z=dp[i-1][1].z;
				} else {
					if(dp[i-1][3].sum>dp[i-1][1].sum) {
						dp[i][2].sum=a[i].y+dp[i-1][3].sum;
						dp[i][2].y=dp[i-1][3].y+1;
						dp[i][2].x=dp[i-1][3].x;
						dp[i][2].z=dp[i-1][3].z;
					} else if(dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][2].sum=a[i].y+dp[i-1][1].sum;
						dp[i][2].y=dp[i-1][1].y+1;
						dp[i][2].x=dp[i-1][1].x;
						dp[i][2].z=dp[i-1][1].z;
					}
				}
			} else {
				if(dp[i-1][3].y>=m) {
					if(dp[i-1][2].sum>dp[i-1][1].sum) {
						dp[i][2].sum=a[i].y+dp[i-1][2].sum;
						dp[i][2].y=dp[i-1][2].y+1;
						dp[i][2].x=dp[i-1][2].x;
						dp[i][2].z=dp[i-1][2].z;
					} else if(dp[i-1][1].sum>=dp[i-1][2].sum) {
						dp[i][2].sum=dp[i-1][1].sum+a[i].y;
						dp[i][2].y=dp[i-1][1].y+1;
						dp[i][2].x=dp[i-1][1].x;
						dp[i][2].z=dp[i-1][1].z;
					}
				} else {
					if(dp[i-1][1].sum>=dp[i-1][2].sum&&dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][2].sum=dp[i-1][1].sum+a[i].y;
						dp[i][2].y=dp[i-1][1].y+1;
						dp[i][2].x=dp[i-1][1].x;
						dp[i][2].z=dp[i-1][1].z;
					} else if(dp[i-1][2].sum>=dp[i-1][1].sum&&dp[i-1][2].sum>=dp[i-1][3].sum) {
						dp[i][2].sum=a[i].y+dp[i-1][2].sum;
						dp[i][2].y=dp[i-1][2].y+1;
						dp[i][2].x=dp[i-1][2].x;
						dp[i][2].z=dp[i-1][2].z;
					} else {
						dp[i][2].sum=a[i].y+dp[i-1][3].sum;
						dp[i][2].y=dp[i-1][3].y+1;
						dp[i][2].x=dp[i-1][3].x;
						dp[i][2].z=dp[i-1][3].z;
					}
				}
			}
		}
		//dp[i][3]
		if(dp[i-1][1].z>=m) {
			if(dp[i-1][2].z>=m) {
				if(dp[i-1][3].z>=m) {
					dp[i][3].sum=0;
					dp[i][3].x=dp[i][3].y=dp[i][3].z=inf;
				} else {
					dp[i][3].sum=a[i].z+dp[i-1][3].sum;
					dp[i][3].z=dp[i-1][3].z+1;
					dp[i][3].x=dp[i-1][3].x;
					dp[i][3].y=dp[i-1][3].y;
				}
			} else {
				if(dp[i-1][3].z>=m) {
					dp[i][3].sum=a[i].z+dp[i-1][2].sum;
					dp[i][3].z=dp[i-1][2].z+1;
					dp[i][3].x=dp[i-1][2].x;
					dp[i][3].y=dp[i-1][2].y;
				} else if(dp[i-1][3].sum>dp[i-1][2].sum) {
					dp[i][3].sum=a[i].z+dp[i-1][3].sum;
					dp[i][3].z=dp[i-1][3].z+1;
					dp[i][3].x=dp[i-1][3].x;
					dp[i][3].y=dp[i-1][3].y;
				} else if(dp[i-1][2].sum>=dp[i-1][3].sum) {
					dp[i][3].sum=a[i].z+dp[i-1][2].sum;
					dp[i][3].z=dp[i-1][2].z+1;
					dp[i][3].x=dp[i-1][2].x;
					dp[i][3].y=dp[i-1][2].y;
				}
			}
		} else {
			if(dp[i-1][2].z>=m) {
				if(dp[i-1][3].z>=m) {
					dp[i][3].sum=dp[i-1][1].sum+a[i].z;
					dp[i][3].z=dp[i-1][1].z+1;
					dp[i][3].x=dp[i-1][1].x;
					dp[i][3].y=dp[i-1][1].y;
				} else {
					if(dp[i-1][3].sum>dp[i-1][1].sum) {
						dp[i][3].sum=a[i].z+dp[i-1][3].sum;
						dp[i][3].z=dp[i-1][3].z+1;
						dp[i][3].x=dp[i-1][3].x;
						dp[i][3].y=dp[i-1][3].y;
					} else if(dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][3].sum=dp[i-1][1].sum+a[i].z;
						dp[i][3].z=dp[i-1][1].z+1;
						dp[i][3].x=dp[i-1][1].x;
						dp[i][3].y=dp[i-1][1].y;
					}
				}
			} else {
				if(dp[i-1][3].z>=m) {
					if(dp[i-1][2].sum>dp[i-1][1].sum) {
						dp[i][3].sum=a[i].z+dp[i-1][2].sum;
						dp[i][3].z=dp[i-1][2].z+1;
						dp[i][3].x=dp[i-1][2].x;
						dp[i][3].y=dp[i-1][2].y;
					} else if(dp[i-1][1].sum>=dp[i-1][2].sum) {
						dp[i][3].sum=dp[i-1][1].sum+a[i].z;
						dp[i][3].z=dp[i-1][1].z+1;
						dp[i][3].x=dp[i-1][1].x;
						dp[i][3].y=dp[i-1][1].y;
					}
				} else {
					if(dp[i-1][1].sum>=dp[i-1][2].sum&&dp[i-1][1].sum>=dp[i-1][3].sum) {
						dp[i][3].sum=dp[i-1][1].sum+a[i].z;
						dp[i][3].z=dp[i-1][1].z+1;
						dp[i][3].x=dp[i-1][1].x;
						dp[i][3].y=dp[i-1][1].y;
					} else if(dp[i-1][2].sum>=dp[i-1][1].sum&&dp[i-1][2].sum>=dp[i-1][3].sum) {
						dp[i][3].sum=a[i].z+dp[i-1][2].sum;
						dp[i][3].z=dp[i-1][2].z+1;
						dp[i][3].x=dp[i-1][2].x;
						dp[i][3].y=dp[i-1][2].y;
					} else {
						dp[i][3].sum=a[i].z+dp[i-1][3].sum;
						dp[i][3].z=dp[i-1][3].z+1;
						dp[i][3].x=dp[i-1][3].x;
						dp[i][3].y=dp[i-1][3].y;
					}
				}
			}
		}
	}
	cout<<max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}

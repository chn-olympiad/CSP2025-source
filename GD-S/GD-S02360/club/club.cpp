#include<bits/stdc++.h>
using namespace std;
int t, n, x, y, z, idb=0, idc=0, idd=0, ans=0;
int a[5], b[100050], c[100050], d[100050];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		idb=0;
		idc=0;
		idd=0;
		for(int i=1; i<=n; i++) {
			cin>>x>>y>>z;
			if(x>=y&&x>=z) {
				ans+=x;
				a[1]++;
				if(y>=z) b[++idb]=x-y;
				else b[++idb]=x-z;
			}
			else if(y>=z) {
				ans+=y;
				a[2]++;
				if(x>=z) c[++idc]=y-x;
				else c[++idc]=y-z;
			}
			else {
				ans+=z;
				a[3]++;
				if(x>=y) d[++idd]=z-x;
				else d[++idd]=z-y;
			}
		}
		if(a[1]>n/2) {
			int l=a[1]-n/2;
			sort(b+1, b+idb+1);
			for(int i=1; i<=l; i++) ans-=b[i];
		}
		else if(a[2]>n/2) {
			int l=a[2]-n/2;
			sort(c+1, c+idc+1);
			for(int i=1; i<=l; i++) ans-=c[i];
		}
		else if(a[3]>n/2) {
			int l=a[3]-n/2;
			sort(d+1, d+idd+1);
			for(int i=1; i<=l; i++) ans-=d[i];
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
} 

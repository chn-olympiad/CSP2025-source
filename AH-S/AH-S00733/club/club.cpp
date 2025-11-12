#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll t,n,s1,s2,s3;
struct node {
	ll x,y,z;
}a[100005];
bool cmp1(node a,node b) {return a.x>b.x;}
bool cmp2(node a,node b) {return a.y>b.y;}
bool cmp3(node a,node b) {return a.z>b.z;}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		s1=s2=s3=0;
		cin >> n;
		for(int i=1; i<=n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a+1,a+n+1,cmp1);
		for(int i=1; i<=n; i++) {
			if(i<=n/2) s1+=a[i].x;
			else s1+=max(a[i].y,a[i].z);
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1; i<=n; i++) {
			if(i<=n/2) s2+=a[i].y;
			else s2+=max(a[i].x,a[i].z); 
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1; i<=n; i++) {
			if(i<=n/2) s3+=a[i].z;
			else s3+=max(a[i].x,a[i].y);
		}
		cout << max(s1,max(s2,s3)) << endl;
	}
	return 0;
}

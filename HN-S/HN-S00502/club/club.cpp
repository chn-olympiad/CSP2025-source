#include <bits/stdc++.h>
using namespace std;
int t,n,r,ans,v[100005];
struct A{
	int x,y,z;
}a[100005];
void dfs(int t,int cnt1,int cnt2,int cnt3,int sum) {
	if (t > n) {
		ans = max(ans,sum);
		return;
	}
	for (int i=1;i<=n;i++) {
		if (v[i]==0 && cnt1+1<=r) {
			sum+=a[i].x;
			v[i] = 1;
			dfs(t+1,cnt1+1,cnt2,cnt3,sum);
			v[i] = 0;
			sum-=a[i].x;
		}
		if (v[i]==0 && cnt2+1<=r) {
			sum+=a[i].y;
			v[i] = 1;
			dfs(t+1,cnt1,cnt2+1,cnt3,sum);
			v[i] = 0;
			sum-=a[i].y;
		}
		if (v[i]==0 && cnt3+1<=r) {
			sum+=a[i].z;
			v[i] = 1;
			dfs(t+1,cnt1,cnt2,cnt3+1,sum);
			v[i] = 0;
			sum-=a[i].z;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;
		r = n/2,ans=0;
		for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 

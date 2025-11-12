#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int a,b,c;
}a[100005];
int vis[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >> t;while(t--){
		memset(vis,0,sizeof vis);
		vector<int> s;
		scanf("%lld",&n);for (int i = 1;i <= n;i++) scanf("%lld %lld %lld",&a[i].a,&a[i].b,&a[i].c);
		int ans = 0,c1 = 0,c2 = 0,c3 = 0;
		for (int i = 1;i <= n;i++){
			if (a[i].a >= a[i].b && a[i].a >= a[i].c) ans += a[i].a,c1++,vis[i] = 1;
			else if (a[i].b >= a[i].a && a[i].b >= a[i].c) ans += a[i].b,c2++,vis[i] = 2;
			else ans += a[i].c,c3++,vis[i] = 3;
		}
		if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2){
			cout << ans << "\n";
			continue;
		}
		if (c1 > n / 2){
			for (int i = 1;i <= n;i++) {
				if (vis[i] != 1) continue;
				s.push_back(max(a[i].b,a[i].c) - a[i].a);
			}
		}else if (c2 > n / 2){
			for (int i = 1;i <= n;i++) {
				if (vis[i] != 2) continue;
				s.push_back(max(a[i].a,a[i].c) - a[i].b);
			}
		}else if (c3 > n / 2){
			for (int i = 1;i <= n;i++) {
				if (vis[i] != 3) continue;
				s.push_back(max(a[i].b,a[i].a) - a[i].c);
			}
		}
		sort(s.begin(),s.end(),greater<int>());
		for (int i = 0; i < max(c1,max(c2,c3)) - n / 2;i++) ans += s[i];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

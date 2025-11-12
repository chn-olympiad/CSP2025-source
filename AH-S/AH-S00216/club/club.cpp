#include<bits/stdc++.h>
using namespace std;
long long t, n, k, ans = 0;
long long vis[5];
struct node{
	long long a, b, c, id;
}d[100010];
bool cmp1(node x, node y){return x.a - x.b - x.c > y.a - y.b - y.c;}
bool cmp2(node x, node y){return x.b - x.a - x.c > y.b - y.a - y.c;}
bool cmp3(node x, node y){return x.c - x.b - x.a > y.c - y.b - y.a;}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		vis[1] = vis[2] = vis[3] = n / 2;
		for(int i = 1; i <= n; i++) cin >> d[i].a >> d[i].b >> d[i].c, d[i].id = 1;
		for(int i = 1; i <= n; i++)
		{
			long long j;
			if(vis[1] > 0)
			{
				sort(d + 1, d + n + 1, cmp1);
				j = 1;
				while(d[j].id == -1) j++;
				ans += d[j].a, d[j].id = -1;
			}
			if(vis[2] > 0)
			{
				sort(d + 1, d + n + 1, cmp2);
				j = 1;
				while(d[j].id == -1) j++;
				ans += d[j].b, d[j].id = -1;
			}
			if(vis[3] > 0)
			{
				sort(d + 1, d + n + 1, cmp3);
				j = 1;
				while(d[j].id == -1) j++;
				ans += d[j].c, d[j].id = -1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

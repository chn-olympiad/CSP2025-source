//GZ-S00029 遵义市第十九中学 余学森 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
	int z, y, n;
	bool operator > (const node &other) {
		return z > other.z;
	}
}a[N];

int t, n, ans, cnt_y = 0, cnt_n = 0, index = 0, pre[N];
int f[240][120],b[N];

void dfs(int now, int tot1, int tot2, int tot3, int sum) {
	index++;
	if (index>=1e8){
		cout<<ans;
		exit(0);
	}
	if(sum+pre[n]-pre[now-1]<ans)return ;
	if (now > n) {
		ans = max(ans, sum);
		return ;
	}

    int t1 = sum + a[now].z,t2=sum + a[now].y,t3=sum + a[now].n;
    if(t1>=t2&&t2>=t3){
    	if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
	    if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
	    if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
	}else if(t1>=t3&&t3>=t2){
    	if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
	    if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
		if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
	}else if(t2>=t1&&t1>=t3){
    	if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
		if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
	    if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
	}else if(t2>=t3&&t3>=t1){
	    if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
	    if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
		if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
	}else if(t3>=t2&&t2>=t1){
	    if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
	    if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
		if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
	}else{
		if (tot1 + 1 <= n / 2) dfs(now + 1, tot1 + 1, tot2, tot3, t1);
		if (tot2 + 1 <= n / 2) dfs(now + 1, tot1, tot2 + 1, tot3, t2);
		if (tot3 + 1 <= n / 2) dfs(now + 1, tot1, tot2, tot3 + 1, t3);
	}
}

int main() {
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
	    ans = -1e9;
		cnt_y = 0, cnt_n = 0;
	    cin >> n;
	    for (int i = 1; i <= n; i++) {
	    	cin >> a[i].z >> a[i].y >> a[i].n;
	    	cnt_y += (a[i].y > 0);
	    	cnt_n += (a[i].n > 0);
	    	pre[i] = pre[i-1]+max(a[i].z,max(a[i].y,a[i].n));
		}
	    if (n <= 15) {
	    	ans = -1e9;
	    	dfs(1, 0, 0, 0, 0);
		} else {
			if (!cnt_y) {
				if (!cnt_n) {
					for (int i =1;i<=n;i++)b[i]=a[i].z;
				    sort(b + 1, b + 1 + n, greater<int>());
					ans = 0;
					for (int i = 1; i <= n / 2; i++) ans += b[i];
				} else {
					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= min(i, n / 2); j++) {
							f[i][j] = max(f[i-1][j]+a[i].y,f[i-1][j-1]+a[i].z);
							if (i==n)ans=max(ans,f[i][j]);
						}    
					}
				}
			} else {
				ans = -1e9;
				dfs(1, 0, 0, 0, 0);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

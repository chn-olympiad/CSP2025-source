#include<bits/stdc++.h>
//ccf
//rp++
//481817542
using namespace std;
int t,n,ans;
array<array<int,4>,100010> a;
int sz[4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0,sz[1] = sz[2] = sz[3] = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] == 0 or a[i][2] == 0 or a[i][3] == 0){
				a[i][1] += 0x3f3f3f3f;
				a[i][2] += 0x3f3f3f3f;
				a[i][3] += 0x3f3f3f3f;
			}
		}
		sort(a.begin() + 1,a.begin() + 1 + n,greater<>());
		for(int i = 1;i <= n;i++){
			if(a[i][1] >= 0x3f3f3f3f or a[i][2] >= 0x3f3f3f3f or a[i][3] >= 0x3f3f3f3f){
				a[i][1] -= 0x3f3f3f3f;
				a[i][2] -= 0x3f3f3f3f;
				a[i][3] -= 0x3f3f3f3f;
			}
		}
		for(int i = 1;i <= n;i++){
			if(a[i][1] >= a[i][2] and a[i][1] >= a[i][3] and sz[1] < n >> 1){
				ans += a[i][1];
				sz[1]++;
			}else if(a[i][2] >= a[i][1] and a[i][2] >= a[i][3] and sz[2] < n >> 1){
				ans += a[i][2];
				sz[2]++;
			}else if(a[i][3] >= a[i][2] and a[i][3] >= a[i][1] and sz[3] < n >> 1){
				ans += a[i][3];
				sz[3]++;
			}else if(sz[1] == n >> 1 and a[i][2] >= a[i][3]){
				ans += a[i][2];
				sz[2]++;
			}else if(sz[1] == n >> 1 and a[i][3] >= a[i][2]){
				ans += a[i][3];
				sz[3]++;
			}else if(sz[2] == n >> 1 and a[i][1]>= a[i][3]){
				ans += a[i][1];
				sz[1]++;
			}else if(sz[2] == n >> 1 and a[i][3] >= a[i][1]){
				ans += a[i][3];
				sz[3]++;
			}else if(sz[3] == n >> 1 and a[i][1]>= a[i][2]){
				ans += a[i][1];
				sz[1]++;
			}else if(sz[3] == n >> 1 and a[i][2] >= a[i][1]){
				ans += a[i][2];
				sz[2]++;
			}
		}
		cout << ans << "\n";
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

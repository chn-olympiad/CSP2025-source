#include<iostream>
#include<queue>
using namespace std;
int t, n, a[100005][5], s[5][100005], cnt[5], ans = 0;
queue<int> q;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.ans", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			q.push(i);
		}
		while(!q.empty()){
			int i = q.front();
			q.pop();
			int j;
			if(a[i][1] > max(a[i][2], a[i][3])) j = 1;
			else if(a[i][2] > max(a[i][1], a[i][3])) j = 2;
			else j = 3;
			if(cnt[j] < n / 2){
				s[j][++cnt[j]] = i;
				ans += a[i][j];
			}
			else{
				int ka = a[s[j][1]][j], k = s[j][1];
				for(int l = 2; l <= cnt[j]; l++){
					if(ka > a[s[j][l]][j]) ka = a[s[j][l]][j], k = s[j][l];
				}
				if(a[i][j] > ka){
					q.push(k);
					s[j][k] = i;
					ans -= a[k][j];
					ans += a[i][j];
				}
				else{
					if(j == 1){
						if(a[i][2] > a[i][3]) j = 2;
						else j = 3;
					}
					else if(j == 2){
						if(a[i][1] > a[i][3]) j = 1;
						else j = 3;
					}
					else{
						if(a[i][2] > a[i][1]) j = 2;
						else j = 1;
					}
					s[j][++cnt[j]] = i;
					ans += a[i][j];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


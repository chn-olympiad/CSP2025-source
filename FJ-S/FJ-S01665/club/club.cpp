#include <bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int x,y,z;
}a[100005];
bool cmpt(Node p,Node q){
	if(p.x != q.x) return p.x > q.x;
	if(p.y != q.y) return p.y > q.y;
	return p.z > q.z;
}
double X,Y,Z;
bool cmp(Node p,Node q){
	if(max(max(p.x - X,p.y - Y),p.z - Z) != max(max(q.x - X,q.y - Y),q.z - Z)) return max(max(p.x - X,p.y - Y),p.z - Z) > max(max(q.x - X,q.y - Y),q.z - Z);
	if(min(max(p.x - X,p.y - Y),p.z - Z) != max(min(q.x - X,q.y - Y),q.z - Z)) return max(max(p.x - X,p.y - Y),p.z - Z) > max(max(q.x - X,q.y - Y),q.z - Z);
	return min(min(p.x - X,p.y - Y),p.z - Z) > min(min(q.x - X,q.y - Y),q.z - Z);
}
int cnt[5] = {0,n / 2,n / 2,n / 2};
int ans = 0;
void dfs(int ind,int sum){
	if(ind == n + 1){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i <= 3;i++){
		if(cnt[i]){
			cnt[i]--;
			if(i == 1) dfs(ind + 1,sum + a[ind].x);
			else if(i == 2) dfs(ind + 1,sum + a[ind].y);
			else dfs(ind + 1,sum + a[ind].z);
			cnt[i]++;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cnt[1] = n / 2;
		cnt[2] = n / 2;
		cnt[3] = n / 2;
		bool flag1 = 1,flag2 = 1;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].z != 0) flag2 = 0;
			if(a[i].y != 0 || a[i].z != 0) flag1 = 0;
		}
		if(n == 2){
			cout << max(max(a[1].x + a[2].y,a[1].x + a[2].z),max(max(a[1].y + a[2].x,a[1].y + a[2].z),max(a[1].z + a[2].x,a[1].z +  a[2].y))) << endl;
			continue;
		}
		if(n == 4){
			ans = 0;
			dfs(1,0);
			cout << ans << endl;
			continue;
		}
		if(n == 10){
			ans = 0;
			dfs(1,0);
			cout << ans << endl;
			continue;
		}
		if(flag1){
			sort(a + 1,a + n + 1,cmpt);
			int sum = 0;
			for(int i = 1;i <= n / 2;i++) sum += a[i].x;
			cout << sum << endl;
			continue;
		}
		if(flag2){
			int sum1 = 0,sum2 = 0;
			for(int i = 1;i <= n;i++){
				sum1 += a[i].x;
				sum2 += a[i].y;
			}
			X = sum1 * 1.0 / n,Y = sum2 * 1.0 / n;
			sort(a + 1,a + n + 1,cmp);
			int sum = 0;
			for(int i = 1;i <= n;i++){
				if(cnt[1] == 0) sum += a[i].y;
				else if(cnt[2] == 0) sum += a[i].x;
				else if(a[i].x - X == a[i].y - Y){
					if(cnt[1] && a[i].x >= a[i].y){
						sum += a[i].x;
						cnt[1]--;
					}
					else{
						sum += a[i].y;
						cnt[2]--;
					}
				}else if(a[i].x - X > a[i].y - Y && cnt[1]){
					sum += a[i].x;
					cnt[1]--;
				}else if(a[i].x - X < a[i].y - Y && cnt[2]){
					sum += a[i].y;
					cnt[2]--;
				}
			}
			cout << sum << endl;
		}
		int sum1 = 0,sum2 = 0,sum3 = 0;
		for(int i = 1;i <= n;i++){
			sum1 += a[i].x;
			sum2 += a[i].y;
			sum3 += a[i].z;
		}
		X = sum1 * 1.0 / n,Y = sum2 * 1.0 / n,Z = sum3 * 1.0 / n;
		sort(a + 1,a + n + 1,cmp);
		int sum = 0;
		for(int i = 1;i <= n;i++){
			int tmax = max(max(a[i].x - X,a[i].y - Y),a[i].z - Z);
			if(cnt[1] == 0 && cnt[2] == 0) sum += a[i].z;
			else if(cnt[1] == 0 && cnt[3] == 0) sum += a[i].y;
			else if(cnt[2] == 0 && cnt[3] == 0) sum += a[i].x;
			else if(a[i].x - X == a[i].y - Y && a[i].y - Y == a[i].z - Z){
				if(cnt[1] && a[i].x >= a[i].y && a[i].x >= a[i].z){
					sum += a[i].x;
					cnt[1]--;
				}else if(cnt[2] && a[i].y >= a[i].x && a[i].y >= a[i].z){
					sum += a[i].y;
					cnt[2]--;
				}else if(cnt[3] && a[i].z >= a[i].x && a[i].z >= a[i].y){
					sum += a[i].z;
					cnt[3]--;
				}
			}else if(a[i].x - X == tmax && a[i].y - Y == tmax){
				if(cnt[1] && a[i].x >= a[i].y){
					sum += a[i].x;
					cnt[1]--;
				}else if(cnt[2] && a[i].y >= a[i].x){
					sum += a[i].y;
					cnt[2]--;
				}
			}else if(a[i].x - X == tmax && a[i].z - Z == tmax){
				if(cnt[1] && a[i].x >= a[i].z){
					sum += a[i].x;
					cnt[1]--;
				}else if(cnt[3] && a[i].z >= a[i].x){
					sum += a[i].z;
					cnt[3]--;
				}
			}else if(a[i].y - Y == tmax && a[i].z - Z == tmax){
				if(cnt[2] && a[i].y >= a[i].z){
					sum += a[i].y;
					cnt[2]--;
				}else if(cnt[3] && a[i].z >= a[i].y){
					sum += a[i].z;
					cnt[3]--;
				}
			}else if(a[i].x - X > a[i].y - Y && a[i].x - X > a[i].z - Z && cnt[1]){
				sum += a[i].x;
				cnt[1]--;
			}else if(a[i].y - Y > a[i].x - X && a[i].y - Y > a[i].z - Z && cnt[2]){
				sum += a[i].y;
				cnt[2]--;
			}else if(a[i].z - Z > a[i].x - X && a[i].z - Z > a[i].y - Y){
				sum += a[i].z;
				cnt[3]--;
			}
		}
		cout << sum << endl;
	}
	return 0;
}


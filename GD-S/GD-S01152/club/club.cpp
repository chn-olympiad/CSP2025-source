#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T, n, sum;
struct nihao{
	int x, y;
	bool operator < (const nihao &W) const{
		return x < W.x;
	}
}a[maxn][5];
struct node{
    int a, b, c, d;
    bool operator < (const node &W) const{
        return d > W.d;
    }
    bool operator > (const node &W) const{
		return d < W.d;
	}
};
int ts_max(int x, int y, int z){
    if(x > y){
        if(x < z) return 3;
        else return 1;
    }else{
        if(y < z) return 3;
        else return 2;
    }
    return 0;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        priority_queue<node> q1;
        priority_queue<node> q2;
        priority_queue<node> q3;
        map<int, int> mp;
        sum = 0;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1].x >> a[i][2].x >> a[i][3].x;
            a[i][1].y = 1, a[i][2].y = 2, a[i][3].y = 3;
            sort(a[i] + 1, a[i] + 4);
            sum += a[i][3].x;
            int cur = a[i][3].y;
            mp[cur]++;
            if(cur == 1) q1.push({a[i][3].x, i, 3, a[i][3].x - a[i][2].x});
            else if(cur == 2) q2.push({a[i][3].x, i, 3, a[i][3].x - a[i][2].x});
            else q3.push({a[i][3].x, i, 3, a[i][3].x - a[i][2].x});
        }
        if(mp[1] <= n / 2 && mp[2] <= n / 2 && mp[3] <= n / 2){
            cout << sum << "\n";
            printf("%d %d %d\n", mp[1], mp[2], mp[3]);
            continue;
        }else{
			sum = 0;
			int nihao = 1;
            //while(mp[1] > n / 2 || mp[2] > n / 2 || mp[3] > n / 2){
            while(nihao--){
                while(mp[1] > n / 2){
                    int y = q1.top().b, z = q1.top().c;
                    if(z == 1){
						sum += q1.top().a;
						q1.pop();
						continue;
					}
                    q1.pop();
                    if(a[y][z-1].y == 2) q2.push({a[y][z-1].x, y, z - 1, a[y][z-1].x - a[y][z-2].x});
                    else q3.push({a[y][z-1].x, y, z - 1, a[y][z-1].x - a[y][z-2].x});
                    mp[1]--;
                    mp[a[y][z-1].y]++;
                }
                while(mp[2] > n / 2){
                    int y = q2.top().b, z = q2.top().c;
                    if(z == 1){
						sum += q2.top().a;
						q2.pop();
						continue;
					}
					q2.pop();
                    if(a[y][z-1].y == 1) q1.push({a[y][z-1].x, y, z - 1, a[y][z-1].x - a[y][z-2].x});
                    else q3.push({a[y][z-1].x, y, z - 1, a[y][z-1].x - a[y][z-2].x});
                    mp[2]--;
                    mp[a[y][z-1].y]++;
                }
                while(mp[3] > n / 2){
                    int y = q3.top().b, z = q3.top().c;
                    if(z == 1){
						sum += q3.top().a;
						q3.pop();
						continue;
					}
                    q3.pop();
                    if(a[y][z-1].y == 1) q1.push({a[y][z-1].x, y, z - 1});
                    else q2.push({a[y][z-1].x, y, z - 1});
                    mp[3]--;
                    mp[a[y][z-1].y]++;
                }
            }
            while(q1.size()){
                sum += q1.top().a;
                q1.pop();
            }
            while(q2.size()){
                sum += q2.top().a;
                q2.pop();
            }
            while(q3.size()){
                sum += q3.top().a;
                q3.pop();
            }
            cout << sum << "\n";
            //printf("%d %d %d\n", mp[1], mp[2], mp[3]);
        }
    }
    return 0;
}


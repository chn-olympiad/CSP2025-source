#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int flag[MAXN], m[MAXN], mm[MAXN], MAX[MAXN], MAXX[MAXN];
struct point{
	int id;
	int f;
	bool operator < (const point &other) const{
		return this->f > other.f;
	}
};
priority_queue <point> q[4];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		memset(flag, 0, sizeof(flag));
		memset(m, 0, sizeof(m));
		memset(mm, 0, sizeof(mm));
		memset(MAX, 0, sizeof(MAX));
		memset(MAXX, 0, sizeof(MAXX));
		for(int i = 1; i <= 3; i++){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			MAX[i] = max(max(a, b), c);
			if(MAX[i] == a){
				MAXX[i] = max(b, c);
				m[i] = 1;
				if(MAXX[i] == b){
					mm[i] = 2;
				}
				else{
					mm[i] = 3;
				}
			}
			else if(MAX[i] == b){
				MAXX[i] = max(a, c);
				m[i] = 2;
				if(MAXX[i] == a){
					mm[i] = 1;
				}
				else{
					mm[i] = 3;
				}
			}
			else{
				MAXX[i] = max(a, b);
				m[i] = 3;
				if(MAXX[i] == a){
					mm[i] = 1;
				}
				else{
					mm[i] = 2;
				}
			}
			flag[i] = MAX[i] - MAXX[i];
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			if(q[m[i]].size() < n / 2){
//				cout << "直接放\n";
				q[m[i]].push({i, flag[i]});
				ans += MAX[i];
			}
			else{
//				cout << "冲突\n";
//				cout << "i,原先:" << flag[i] << ' ' << q[m[i]].top().f << "\n";
				if(flag[i] > q[m[i]].top().f){
					int j = q[m[i]].top().id;
					ans += MAX[i] - flag[j];
					q[mm[j]].push({j, flag[j]});
					q[m[i]].pop();
					q[m[i]].push({i, flag[i]});
				}
				else{
					ans += MAXX[i];
					q[mm[i]].push({i, flag[i]});
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
CSP-S 2025 游寄（伪） 
0min开T1，思考了20分钟没思路，遂开T2
经过一番烧烤，发现T2在k=0时好像是一个最小生成树，直接做了一波，应该能拿16pts
T2预估得分：16pts 
75min又回来看T1，深度烧烤了一会想到了一个差不多的贪心解法，但是没有办法证明正确性
95min不管了直接写    PS：为啥每年都是大贪心起手啊？没话说了，我还每次都没法证明正确性，服了
114min马完，大样例全过，拿下（应该吧？）
T1预估得分:100pts 
115min猛攻T3！！！！！
165min猛攻失败！！！！
特殊类型根本看不懂，手搓类型B搓了快1h没搓出来
蒜鸟蒜鸟，写个暴力吧
成功拿下样例1,2
应该有20pts吧？
T3预估得分：20pts
180min开T4
不会，骗不了一点分，夏波
T4预估得分：0pts 
最终预估得分：100pts + 16pts + 20pts + 0pts = 136pts
AFO
PS：最后20min蒸不动了，突发奇想决定写这篇游寄（伪）来给周围的兄弟们上上压力，
很明显能看出来我旁边那个哥们压力暴大，手不停在抖，嘻嘻 
*/

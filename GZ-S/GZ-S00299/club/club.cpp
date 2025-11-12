//  GZ-S00299 游景智 毕节梁才学校
#include<bits/stdc++.h>
using namespace std;
// 分为三类
// 第一类 最爱1部门
// 第二类 最爱2部门
// 第三类 最爱三部门
const int N = 1e5 + 10;
int ans;
struct NODE{
	int x, y, z;
};
bool cmp(NODE a, NODE b){
	int x = a.x, y = a.y, z = a.z;
	int mi;
	if(x >= y && x >= z){
		mi = min(abs(x - y), abs(x - z));
	}else if(y >= x && y >= z){
		mi = min(abs(y - x), abs(y - z));
	}else{
		mi = min(abs(z - x), abs(z - y));
	}
	int MI;
	x = b.x, y = b.y, z = b.z;
	if(x >= y && x >= z){
		MI = min(abs(x - y), abs(x - z));
	}else if(y >= x && y >= z){
		MI = min(abs(y - x), abs(y - z));
	}else{
		MI = min(abs(z - x), abs(z - y));
	}
	return mi > MI; // 我要读back所以这样 
}
int T;
int n;
vector<NODE> a, b, c;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	scanf("%d", &T);
	while(T--){
		ans = 0;
		a.clear();
		b.clear();
		c.clear();
		scanf("%d", &n);		
		for(int i = 1; i <= n; i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if(x >= y && x >= z){
				a.push_back((NODE){x, y, z});
				ans += x;
			}else if(y >= x && y >= z){
				b.push_back((NODE){x, y, z});
				ans += y;
			}else{
				c.push_back((NODE){x, y, z});
				ans += z;
			}
		}
		sort(a.begin(), a.end(), cmp);
		while((int)a.size() > n / 2){
			int x = a.back().x;
			int y = a.back().y;
			int z = a.back().z;
			if(abs(x - y) <= abs(x - z)){
				ans = ans - x + y;
				b.push_back(a.back());
				a.pop_back();
			}else{
				ans = ans - x + z;
				c.push_back(a.back());
				a.pop_back();
			}
		}
		sort(b.begin(), b.end(), cmp);
//		for(int i = 0; i< (int)b.size(); i++){
//			int x, y, z;
//			x = b[i].x , y = b[i].y, z= b[i].z;
//			printf("%d %d %d\n", x, y, z);
//		}
		while((int)b.size() > n / 2){
			int x = b.back().x;
			int y = b.back().y;
			int z = b.back().z;
			if(abs(y - x) <= abs(y - z)){
				ans = ans - y + x;
				a.push_back(b.back());
				b.pop_back();
			}else{
				ans = ans - y + z;
				c.push_back(b.back());
				b.pop_back();
			}
		}		
//		printf("=%d\n", (int)b.size());
		sort(c.begin(), c.end(), cmp);
		while((int)c.size() > n / 2){
			int x = c.back().x;
			int y = c.back().y;
			int z = c.back().z;
			if(abs(z - x) <= abs(z - y)){
				ans = ans - z + x;
				a.push_back(c.back());
				c.pop_back();
			}else{
				ans = ans - z + y;
				b.push_back(c.back());
				c.pop_back();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

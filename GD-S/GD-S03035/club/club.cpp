#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e5 + 10;

struct point{
	int a1, a2, a3;
	int xuan;//选哪个
}edge[N];

int t, n, tong[4], ch[N], a1, a2, a3;//ch为改变多少 

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		int ans = 0;
		tong[1] = 0;
		tong[2] = 0;
		tong[3] = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++) ch[i] = INT_MAX;
		for(int i = 1; i <= n; i++){
			scanf("%lld %lld %lld", &a1, &a2, &a3);
			edge[i].a1 = a1, edge[i].a2 = a2, edge[i].a3 = a3;
			if(a1 >= a2 && a1 >= a3) edge[i].xuan = 1, tong[1]++, ans += a1;
			else if(a2 >= a3 && a2 >= a1) edge[i].xuan = 2, tong[2]++, ans += a2;
			else edge[i].xuan = 3, tong[3]++, ans += a3;
		}
		int cnt = 0;
//		cout << tong[1] << " " << tong[2] << " " << tong[3] << endl;
		if(tong[1] > n / 2){
			for(int i = 1; i <= n; i++){
//				cout << " ! " << a1 << " " << a2 << " " << a3 << endl;
				a1 = edge[i].a1, a2 = edge[i].a2, a3 = edge[i].a3;
				if(edge[i].xuan == 1) ch[i] = min(a1 - a2, a1 - a3);
//				cout << edge[i].xuan << " " << ch[i] << " " << i << endl;
			}
			sort(ch + 1, ch + 1 + n);
//			for(int i = 1; i <= n; i++) cout << ch[i];
//			cout << tong[1] - n / 2 << endl;
			for(int i = 1; i <= tong[1] - n / 2; i++) cnt += ch[i];
//			cout << cnt << endl;
		}else if(tong[2] > n / 2){
			for(int i = 1; i <= n; i++){
				a1 = edge[i].a1, a2 = edge[i].a2, a3 = edge[i].a3;
//				cout << " ! " << a1 << " " << a2 << " " << a3 << endl;
				if(edge[i].xuan == 2) ch[i] = min(a2 - a1, a2 - a3);
			}
			sort(ch + 1, ch + 1 + n);
			for(int i = 1; i <= tong[2] - n / 2; i++) cnt += ch[i];
		}else if(tong[3] > n / 2){
			for(int i = 1; i <= n; i++){
				a1 = edge[i].a1, a2 = edge[i].a2, a3 = edge[i].a3;	
				if(edge[i].xuan == 3) ch[i] = min(a3 - a1, a3 - a2);
			}
			sort(ch + 1, ch + 1 + n);
			for(int i = 1; i <= tong[3] - n / 2; i++) cnt += ch[i];
		}
//		cout << ans << " " << cnt << endl;
		cout << ans - cnt << endl;
	}
}
/*
Ren5Jie4Di4Ling5%
5211673674
*/
/*
先全部选最高，如果有超出的话
如4
4 2 1
4 3 2
5 3 4
4 1 4
最高全部是1；
则超出部分改为第二高的
代价分别为 -2 -1 0 -1 0
故答案即 4 + 4 + 5 + 4 - 1 - 0 = 16 
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/

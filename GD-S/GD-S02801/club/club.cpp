#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define debug(x) cerr << #x << " = " << x << "\n"

const int maxn = 1e5 + 10;

struct pp{
	int a_1, a_2, a_3, a_1_2, a_2_1;
//	int a_1_2 , a_1_3, a_2_3, a_3_1, a_2_1, a_3_2;
}a[maxn];

struct node{
	ui a_i, id;
}; 

//bool cmp(node x, node y){
//	return (x.a_i == y.a_i) ? (x.id < y.id) : (x.a_i < y.a_i);
//}

bool cmp1(pp x, pp y){
	return x.a_1 < y.a_1;
}

//ui dp[maxn], fl[3];
ui dp[4], fl[4];//, dp_c[4]

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ui t, n, pp_max;
	cin >> t;
	while(t--){
		ui ans = 0;
		bool f_1 = 1;  
		cin >> n;
		pp_max = n >> 1;
//		memset(dp_c, 0, sizeof(dp_c));
		dp[0] = fl[3] = fl[1] = fl[2] = dp[3] = dp[1] = dp[2] = 0;
		for(ui i = 1; i <= n; ++i){
			cin >> a[i].a_1 >> a[i].a_2 >> a[i].a_3;
			if(a[i].a_2){
				f_1 = 0;
			}if(a[i].a_3){
				f_1 = 0;
//				f_2 = 0;
			}
			a[i].a_1_2 = a[i].a_1 - a[i].a_2;
//			a[i].a_1_3 = a[i].a_1 - a[i].a_3;
//			a[i].a_2_3 = a[i].a_2 - a[i].a_3;
//			a[i].a_3_1 = a[i].a_3 - a[i].a_1;
			a[i].a_2_1 = a[i].a_2 - a[i].a_1;
//			a[i].a_3_2 = a[i].a_3 - a[i].a_2;
		}
		if(f_1){
			sort(a + 1, a + 1 + n, cmp1);
			for(ui i = pp_max + 1; i <= n; ++i){
				ans += a[i].a_1;
			}
			cout << ans << '\n';
		}
//		else if(f_2){
//			
//		}
		else{
			for(ui i = 1; i <= n; ++i){
	//			node x[3];
	//			x[0].a_i = a[i].a_1;
	//			x[0].id = 1;
	//			x[1].a_i = a[i].a_2;
	//			x[1].id = 2;
	//			x[2].a_i = a[i].a_3;
	//			x[2].id = 3;
	//			sort(x, x + 3, cmp);
	//			if(fl[x[2].id] < pp_max){
	//				dp[i][]
	//			}
	//			if(fl[1] < pp_max){
	//				dp[i] = max(dp[i-1] + a[i].a_1, dp[i]);
	//			}else{
	//				dp[i] = max(dp[i-1] + a[i].a_1, dp[i])
	//			}
	//			if
				ui zc[4] = {}, f[4] = {};
	//			stack<int> aaa;
				if(fl[1] < pp_max){
					zc[1] = dp[0] + a[i].a_1;
					f[1] = 1;
				}else{
					zc[1] = max(a[i].a_1 + max(dp[2], dp[3]), max(dp[0] + a[i].a_2, dp[0] + a[i].a_3));
				}
				if(fl[2] < pp_max){
					zc[2] = dp[0] + a[i].a_2;
					f[2] = 2;
				}else{
					zc[2] = max(a[i].a_2 + max(dp[1], dp[3]), max(dp[0] + a[i].a_1, dp[0] + a[i].a_3));
				}
				if(fl[3] < pp_max){
					zc[3] = dp[0] + a[i].a_3;
					f[3] = 3;
				}else{
					zc[3] = max(a[i].a_3 + max(dp[1], dp[2]), max(dp[0] + a[i].a_1, dp[0] + a[i].a_2));
				}
//				for(int i = 1; i <= 3; ++i){
//					cerr << i << "	"; 
//	//				debug(i);
//	//				debug(dp_c[i]);
//				}cerr << "\n";
//	//			for(int i = 1; i <= 3; ++i){
//	//				cerr << dp_c[i] << "	"; 
//	////				debug(i);
//	////				debug();
//	//			}cerr << "dp_c\n";
//				for(int i = 1; i <= 3; ++i){
//					cerr << dp[i] << "	"; 
//	//				debug(i);
//	//				debug();
//				}cerr << "dp\n";
//				for(int i = 1; i <= 3; ++i){
//					cerr << zc[i] << "	"; 
//	//				debug(i);
//	//				debug();
//				}cerr << "zc\n";
//				for(int i = 1; i <= 3; ++i){
//					cerr << fl[i] << "	"; 
//	//				debug(i);
//	//				debug();
//				}cerr << "fl\n";
//				debug(dp[0]);
	//			dp_c[1] = dp[1];
	//			dp_c[2] = dp[2];
	//			dp_c[3] = dp[3];
				dp[1] = zc[1];
				dp[2] = zc[2];
				dp[3] = zc[3];
				if(zc[2] > zc[3]){
					if(zc[1] > zc[2]){
						++fl[f[1]];
					}else{
						++fl[f[2]];
					}
				}else{
					if(zc[1] > zc[3]){
						++fl[f[1]];
					}else{
						++fl[f[3]];
					}
				}
				dp[0] = max(zc[1], max(zc[2], zc[3]));
			}
			cout << dp[0] << '\n';
		}
	}
	return 0;
}
/*
1
6
1 2 3
1 2 4
0 2 0
1 0 9
0 0 1
1 1 10

1
6
1 0 0
4 0 0
9 0 0
11 0 0
3 0 0
2 0 0

*/

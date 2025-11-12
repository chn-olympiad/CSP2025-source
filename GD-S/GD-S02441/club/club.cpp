// 如何呢？有能怎？
// 最后的倔强还是有 WA。
// 我只是希望出奇葩大赏的时候你会注意到这个：//freeopen(club.cpp, r, stdout):

// Uid:1062508

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int T;
namespace Subtask{
	int n, t[4], cnta, cntb, cntc, ans[15];
	struct STRUCT{
		int f, s, t;
	}a[100005];
	bool cmp(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s < b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp3(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s < b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp2(int x, int y){ return x > y; }
		bool cmp17(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s > b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp4(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s < b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp5(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s < b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp6(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s > b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp7(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s < b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp8(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s < b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp9(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s > b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp10(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s > b.s;
			}
			return a.f < b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp11(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s < b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp12(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s > b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t < b.f + b.s + b.t;
	}
	bool cmp13(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s < b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp14(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t < b.t;
				return a.s > b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	bool cmp15(STRUCT a, STRUCT b){
		if(a.f + a.s + a.t == b.f + b.s + b.t){
			if(a.f == b.f){
				if(a.s == b.s)
					return a.t > b.t;
				return a.s > b.s;
			}
			return a.f > b.f;
		}
		return a.f + a.s + a.t > b.f + b.s + b.t;
	}
	void main(){
		cnta = cntb = cntc = 0;
		memset(ans, 0, sizeof(ans));
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> a[i].f >> a[i].s >> a[i].t;
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[1] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[1] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[1] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp3);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[2] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[2] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[2] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp4);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[3] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[3] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[3] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp5);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[4] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[4] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[4] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp6);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[5] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[5] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[5] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp7);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[6] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[6] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[6] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp8);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[7] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[7] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[7] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp9);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[8] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[8] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[8] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp10);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[9] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[9] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[9] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp11);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[10] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[10] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[10] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp12);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[11] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[11] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[11] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp13);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[12] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[12] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[12] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp14);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[13] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[13] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[13] += t[j];
					break;
				}
			}
		}
		cnta = cntb = cntc = 0;
		sort(a + 1, a + 1 + n, cmp15);
		for(int i = 1;i <= n;i++){
			t[1] = a[i].f, t[2] = a[i].s, t[3] = a[i].t;
			sort(t + 1, t + 4, cmp2);
			for(int j = 1;j <= 3;j++){
				if(t[j] == a[i].f && cnta < n / 2){
					cnta++, ans[14] += t[j];
					break;
				}
				if(t[j] == a[i].s && cntb < n / 2){
					cntb++, ans[14] += t[j];
					break;
				}
				if(t[j] == a[i].t && cntc < n / 2){
					cntc++, ans[14] += t[j];
					break;
				}
			}
		}
		int anss = -1e9;
		for(int i = 1;i <= n;i++)
			anss = max(anss, ans[i]);
		cout << anss << endl;
		return;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
		Subtask::main();
	return 0;
} 

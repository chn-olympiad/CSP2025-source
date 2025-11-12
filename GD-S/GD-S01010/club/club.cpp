#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct club{
	int val,num;
};
int T;
int n;
club a[N][10];
int b[N];
int fc,sc,tc;
int moreclub;
vector<club> club1, club2, club3;
vector<int> q;
bool cmp(club x, club y){
	return x.val > y.val;
}
bool cmp1(club x, club y){
	return x.val < y.val;
}
void qh(){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum = sum + a[i][1].val;
	}
	printf("%lld\n",sum);
	return;
}
void print(){
	for(int i = 1; i <= n; i++){
		cout << a[i][1].val << ' ' << a[i][1].num << endl;
	}
	cout << endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		fc = sc = tc = 0;
		club1.clear();
		club2.clear();
		club3.clear();
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld",&a[i][1].val,&a[i][2].val,&a[i][3].val);
			a[i][1].num = 1;
			a[i][2].num = 2;
			a[i][3].num = 3;
			sort(a[i] + 1, a[i] + 1 + 3, cmp);
			if(a[i][1].num == 1){
				fc++;
				club1.push_back(club{a[i][1].val - a[i][2].val, i});
			} else if(a[i][1].num == 2){
				sc++;
				club2.push_back(club{a[i][1].val - a[i][2].val, i});
			} else{
				tc++;
				club3.push_back(club{a[i][1].val - a[i][2].val, i});
			}//*/
		}
//		print();
		if(fc >= sc && fc >= tc){
			moreclub = 1;
			if(fc <= n / 2){
				qh();
				continue;
			}
		} else if(sc >= fc && sc >= tc){
			moreclub = 2;
			if(sc <= n / 2){
				qh();
				continue;
			}
		} else{
			moreclub = 3;
			if(tc <= n / 2){
				qh();
				continue;
			}
		}
//		print();
		if(moreclub == 1){
			sort(club1.begin(), club1.end(), cmp1);
//			print();
			for(int i = 1; i <= fc - n / 2; i++){
				club f = club1[i - 1];
				if(a[f.num][2].num == 2){
					sc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club2.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				} else{
					tc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club3.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				}
			}
//			print();
			if(sc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club2.size(); i++){
					club f = club2[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			} else if(tc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club3.size(); i++){
					club f = club3[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			}
		} else if(moreclub == 2){
			sort(club2.begin(), club2.end(), cmp1);
//			print();
//			cout << sc << ' ' << n / 2 << endl;
			for(int i = 1; i <= sc - n / 2; i++){
				club f = club2[i - 1];
//				cout << i << ' '  << sc - n / 2 << endl;
				if(a[f.num][2].num == 1){
					fc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club1.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				} else{
					tc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club3.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				}
			}
//			print();
			if(fc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club1.size(); i++){
					club f = club1[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			} else if(tc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club3.size(); i++){
					club f = club3[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			}
		} else{
			sort(club3.begin(), club3.end(), cmp1);
//			print();
			for(int i = 1; i <= tc - n / 2; i++){
				club f = club3[i - 1];
				if(a[f.num][2].num == 2){
					sc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club2.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				} else{
					fc++;
					swap(a[f.num][2],a[f.num][1]);
					swap(a[f.num][2],a[f.num][3]);
					club1.push_back(club{a[f.num][1].val - a[f.num][2].val, i});
				}
			}
//			print();
			if(sc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club2.size(); i++){
					club f = club2[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			} else if(fc > n / 2){
				int maxn,maxx;
				maxn = maxx = 0;
				for(int i = 0; i < club3.size(); i++){
					club f = club1[i];
					if(f.val > maxn){
						maxn = f.val;
						maxx = f.num;
					}
				}
				swap(a[maxx][1],a[maxx][2]);
			}
		}
		qh();
	}
	return 0;
}
/*
3
4
2 1 4
2 4 3
3 4 5
5 1 3
4
0 0 1
0 0 1
0 0 2
0 0 2
2
9 8 10
0 0 4

*/

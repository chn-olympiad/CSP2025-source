#include <bits/stdc++.h>
using namespace std;


struct node{
	int val,idx,opt;
};

int _,n,mx;

bool cmp(node x, node y){
	if (x.val != y.val) return x.val > y.val;
	if (x.idx != y.idx) return x.idx > y.idx;
	if (x.opt != y.opt) return x.opt > y.opt;
}

//bool check(int a[]){
//	long long sum = 0;
//	for (int i = 1;i <= 3;++i){
//		sum += a[i];
//	}
//	return sum == n;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> _;
	while (_--){
		long long ans = -1;
		vector<node> v;
		cin >> n;
		mx = n/2;
		if (n <= 30){
			for (int i = 1;i <= n;++i){
				for (int j = 1;j <= 3;++j){
					int t;cin >> t;
					v.push_back({t,i,j});
				}
			}
			sort(v.begin(),v.end(),cmp);
			for (int X = 0;X < v.size();++X){
				//vector<int> chs;
				int len = n-1,cnt_chs[5]={};
				long long sum = v[X].val;
				bool cnt_idx[100005]={};
				cnt_idx[v[X].idx] = 1;
				cnt_chs[v[X].opt] += 1;
				//chs.push_back(X);
				for (int x = 0;len > 0 && x < v.size();++x){
					if (x == X) continue;
					
					int val = v[x].val, idx = v[x].idx, opt = v[x].opt;
					
					if (cnt_idx[idx]) continue;
					cnt_chs[opt] += 1;
					if (cnt_chs[opt] > mx){
						cnt_chs[opt] -= 1;
						continue;
					}
					cnt_idx[idx] = 1;
					sum += val;
					len--;
					//if (check(cnt_chs)) break;
				}
				if (len) continue;
//				long long sum = 0;
//				for (auto &i:chs){
//					cout << i << ' ';sum += v[i].val;
//				}
				ans = max(ans,sum);
			}
			cout << ans << endl;
		}
		else{
			vector<int> v;
			for (int i = 1;i <= n;++i){
				for (int j = 1;j <= 3;++j){
					int t;cin >> t;
					if (j == 1) v.push_back(t);
				}
			}
			sort(v.begin(),v.end(),greater<int>());
			for (int i = 0;i < v.size() && i <= mx;++i){
				ans += v[i];
			}
			cout << ans << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5;
int n, k, cnt = 0;
int a[MAXN];
struct node{
	int le, ri;
	int si;
};
vector<node> v;
bool flag[MAXN];

void pre(const int &l, const int &r){
	int ans = a[l];
	for(int i = l+1; i <= r; i++){
		ans ^= a[i];
	}
	if(ans == k){
		int s = r-l+1;
		v.push_back({l, r, s});
	}
}

bool cmp(const node &x, const node &y){
	return x.si < y.si;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++) pre(l, r);
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < v.size(); i++){
		bool f = true;

		for(int j = v[i].le; j <= v[i].ri; j++){
			if(flag[j]){
				f = false;
				break;
			}
		}

		if(f){
			cnt++;
			for(int j = v[i].le; j <= v[i].ri; j++){
				flag[j] = true;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}
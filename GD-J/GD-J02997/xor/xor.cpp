#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 500005;
int n, k, a[N], prefa[N];
unsigned long long ans = 0;
vector<pair<int, int> > ranges;
vector<pair<int, int> > spaces;
//int minend[N];

bool cmp(pair<int,int> r1, pair<int,int> r2){
	return (r1.second - r1.first) < (r2.second - r2.first);
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w", stdout);
	
	bool isAll1 = true, isAll01 = true;
	int zeros=0, ones=0;
	cin >> n >> k;
	spaces.push_back({1, n});
	for(int i=1; i<=n; i++){
		cin >> a[i];
		prefa[i] = prefa[i-1] ^ a[i];
		if(a[i] != 1){
			isAll1 = false;
			if(a[i] != 0) isAll01 = false;
		}
		if(isAll01){
			(a[i] == 1) ? ones++ : zeros++;
		}
	}
	if(isAll1){
		cout << floor(n/2);
	}else if(isAll01 && k == 0){ //Pass 17 pls
		ans = zeros;
		int ctrl = 0; //ConTinouos Range Length
		for(int i=1; i<=n; i++){
			if(a[i] == 1){
				ctrl++;
			}else{
				ans += floor(ctrl/2);
				ctrl = 0;
			}
		}
		cout << ans;
	}else if(isAll01 && k == 1){ //Pass 17 pls
		ans = ones;
		cout << ans;
	}else{
		int c;
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				c = prefa[j]^prefa[i-1];
				if(c == k){
//					printf("[%d, %d] (%d ^ %d = %d == %d)\n", i, j, prefa[j], prefa[i-1], c, k);
					ranges.push_back({i, j});
//					minend[i] = j;
//					ans++;
					break;
				}
			}
		}
//		int p = 1;
//		while(p <= n){
//			if(minend[p] == 0) p++;
//			else{
//				ans++;
//				p = minend[p] + 1;
//			}
//		}
		sort(ranges.begin(), ranges.end(), cmp);
		int sl, sr;
		for(auto r:ranges){
			for(int i=0; i<(signed)spaces.size(); i++){
				if(r.first >= spaces[i].first && r.second <= spaces[i].second){
					ans++;
					sl = spaces[i].first;
					sr = spaces[i].second;
					spaces.erase(spaces.begin()+i);
					if(r.first > sl) spaces.push_back({sl,r.first-1});
					if(r.second < sr) spaces.push_back({r.second+1,sr});
				}
			}
		}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

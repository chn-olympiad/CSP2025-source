#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Node{
	int idx, idx2, w, w2;
};

int t, n, res;
int cnt[3];
Node mem[N];

void solve(int a, int b, int c, int k){
	if(a >= b){
		if(a >= c){
			mem[k].idx = 0;
			mem[k].w = a;
			if(b >= c){
				mem[k].idx2 = 1;
				mem[k].w2 = b;
			}else{
				mem[k].idx2 = 2;
				mem[k].w2 = c;
			}
		}else{
			mem[k].idx = 2;
			mem[k].w = c;
			mem[k].idx2 = 0;
			mem[k].w2 = a;
		}
	}else{
		if(b >= c){
			mem[k].idx = 1;
			mem[k].w = b;
			if(a >= c){
				mem[k].idx2 = 0;
				mem[k].w2 = a;
			}else{
				mem[k].idx2 = 2;
				mem[k].w2 = c;
			}
		}else{
			mem[k].idx = 2;
			mem[k].w = c;
			mem[k].idx2 = 1;
			mem[k].w2 = b;
		}
	}
}

bool cmp(Node a, Node b){
	return a.w - a.w2 > b.w - b.w2;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		res = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			solve(a, b, c, i);
		}
		sort(mem, mem + n, cmp);
		for(int i = 0; i < n; i++){
			if(cnt[mem[i].idx] < (n >> 1)){
				res += mem[i].w;
				cnt[mem[i].idx]++;
			}else{
				res += mem[i].w2;
				cnt[mem[i].idx2]++;
			}
		}
		cout << res << endl;
	}
	return 0;
}

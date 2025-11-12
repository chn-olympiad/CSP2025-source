#include <bits/stdc++.h>
using namespace std;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		f = (ch == '-' ? -f : f);
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, Arr[100010][4], Cnt[4], Ans;
vector<int> vec[4];

void solve(){
	Ans = 0;
	n = read();
	Cnt[1] = Cnt[2] = Cnt[3] = 0;
	vec[1].clear(), vec[2].clear(), vec[3].clear();
	for(int i = 1; i <= n; i ++){
		Arr[i][1] = read(), Arr[i][2] = read(), Arr[i][3] = read();
		if(Arr[i][1] >= Arr[i][2] && Arr[i][1] >= Arr[i][3]) ++ Cnt[1], vec[1].emplace_back(i);
		else if(Arr[i][2] >= Arr[i][1] && Arr[i][2] >= Arr[i][3]) ++ Cnt[2], vec[2].emplace_back(i);
		else ++ Cnt[3], vec[3].emplace_back(i);
		Ans += max(Arr[i][1], max(Arr[i][2], Arr[i][3]));
	}
	if(Cnt[1] > n / 2){
		for(int i = 0; i < vec[1].size(); i ++){
			int id = vec[1][i];
			vec[1][i] = Arr[id][1] - max(Arr[id][2], Arr[id][3]);
		}
		sort(vec[1].begin(), vec[1].end());
		for(int i = 0, j = 1; i < vec[1].size() && j <= Cnt[1] - n / 2; i ++, j ++){
			Ans -= vec[1][i];
		}
	}else if(Cnt[2] > n / 2){
		for(int i = 0; i < vec[2].size(); i ++){
			int id = vec[2][i];
			vec[2][i] = Arr[id][2] - max(Arr[id][1], Arr[id][3]);
		}
		sort(vec[2].begin(), vec[2].end());
		for(int i = 0, j = 1; i < vec[2].size() && j <= Cnt[2] - n / 2; i ++, j ++){
			Ans -= vec[2][i];
		}
	}else if(Cnt[3] > n / 2){
		for(int i = 0; i < vec[3].size(); i ++){
			int id = vec[3][i];
			vec[3][i] = Arr[id][3] - max(Arr[id][1], Arr[id][2]);
		}
		sort(vec[3].begin(), vec[3].end());
		for(int i = 0, j = 1; i < vec[3].size() && j <= Cnt[3] - n / 2; i ++, j ++){
			Ans -= vec[3][i];
		}
	}
	write(Ans), putchar('\n');
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while(T --){
		solve();
	}
}

#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;

const int NN = 5010;
int L[NN], ans, N;
vector<int> bb;
void DFS(int num, int last, int now, int sum, int mxi){
	if(now == num){
		ans += (sum > 2 * mxi);
//		if(sum > 2 * mxi)
//			for(int f : bb)
//				cout << f << ' ';
//		cout << '\n';
		return ;
	}
	
	_loopc(i, last + 1, N){
		bb.push_back(L[i]);
		DFS(num, i, now + 1, sum + L[i], max(mxi, L[i]));
		bb.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> N;
	_loopc(i, 1, N)
		cin >> L[i];
	
	int answer = 0;
	_loopc(i, 3, N){
		DFS(i, 0, 0, 0, 0);
		answer += ans;
		ans = 0;
	}
	
	cout << answer;
	return 0;
}
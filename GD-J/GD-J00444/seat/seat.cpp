#include <bits/stdc++.h>
using namespace std;
int n, m;
int xr;
int nx = 1, ny = 1;
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; ++i){
		int tmp;
		cin >> tmp;
		if(i == 1) xr = tmp;
		q.push(tmp);
	}
	if(xr == q.top()){
		cout << 1 << " " << 1;
		return 0;
	}
	q.pop();
	while(q.size()){
		if((nx % 2 == 0 && ny == 1) || (nx % 2 == 1 && ny == n)){
			nx++;
		}else{
			if(nx % 2 == 0) ny--;
			else ny++;
		}
		if(q.top() == xr){
			cout << nx << " " << ny;
			return 0;
		}
		q.pop();
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, s, r, d, col, row;
vector<int> l;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	s = n * m;
	l.resize(s);
	
	for(int i=0;i<s;i++){
		cin >> l[i];
	}
	
	r = l[0];
	
	sort(l.begin(), l.end(), [](int a, int b){return a>b;});
	d = distance(l.begin(), find(l.begin(), l.end(), r));
	
	col = d / n;
	row = d%n;
	if(col%2) row = m-1-row;
	
	cout << col+1 << " " << row+1;
	
	return 0;
}
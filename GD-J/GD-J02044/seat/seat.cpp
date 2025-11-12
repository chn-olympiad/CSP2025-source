#include <iostream>
#include <algorithm>
bool cmp(int a,int b) {
	return a > b;
}
using namespace std;
int n,m,value[101],Rscore,ptr;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int times = n * m;
	for(int i = 0;i < times;++i) {
		cin >> value[i];
	}
	Rscore = value[0];
	sort(value,value + times,cmp);
	for(int i = 0;i < times;++i) {
		if(value[i] == Rscore) {
			ptr = i;
			break;
		}
	}
	int c = ptr / n + 1;
	int r = 0;
	if(c & 1) {
		r = ptr % n + 1;
	} else {
		r = n - ptr % n;
	}
	cout << c << ' ' << r;
	return 0;
}


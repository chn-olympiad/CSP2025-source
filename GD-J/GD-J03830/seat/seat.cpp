#include <iostream>
#include<string>
#include<algorithm> 
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s = n*m;
	vector<int>a(s + 1);
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int tg = a[1];
	sort(a.begin() + 1,a.begin() + s + 1);
	int pos = lower_bound(a.begin() + 1, a.begin() + s + 1, tg) - a.begin();
	int _npos = s - pos + 1; 
	int c = ceil(1.0 * _npos / n);
	bool isdown = c % 2;//0向上，1向下 
	int r;
	//int _tmp = pos - n * c;
	int _tmp = (_npos - 1) % n + 1;
	if(isdown){
		r = _tmp;
	}else{
		r = n - _tmp + 1;
	}
	cout<< c << ' ' << r;
	return 0;
}

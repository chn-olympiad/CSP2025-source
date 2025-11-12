#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt(0);
	cin>>n>>m;
	int N = n*m;
	vector<int> v(N);
	for(int i = 0; i<N; ++i)cin>>v[i];
	for(int i = 1; i<N; ++i)if(v[i]>v[0])++cnt;
	int c = cnt / n;
	int r = cnt % n;
	if(c & 1) r = n - r - 1;
	cout<<(c+1)<<' '<<(r+1);
	return 0;
}

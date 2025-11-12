#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;cin >> n >> m;
	vector<pair<int,int>> v;
	for (int i=1,a;i<=n*m;++i){
		cin >> a;v.emplace_back(a,i);
	}
	sort(v.begin(),v.end(),greater<pair<int,int>>());
	int x=1,y=1;int id=0;
	while (id<n*m){
		if (v[id].second==1){
			cout<<x<<" "<<y<<"\n";
			break;
		}
		++id;
		if (x&1) ++y;
		else --y;
		if (y==0) y=1,++x;
		if (y==n+1) y=n,++x;
	}
	cout.flush();
	return 0;
}
/*
锦官锦绣谁去来
模拟即可
4 5
11 2 1 6 3 4 2 9 12 45 19 198 10 114514 1919810 114 514 1919 810 20
*/
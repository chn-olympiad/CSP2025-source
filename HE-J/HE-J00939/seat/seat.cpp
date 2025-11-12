#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,bool> PIB;
int n,m;
PIB a[114514];
bool cmp(PIB x,PIB y) {
	return x.first > y.first;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n * m;i++) {
		cin>>a[i].first;
		if (i == 1) a[i].second = 1;
	}
	sort(a + 1,a + (n * m) + 1,cmp);
	int c = 1,r = 1,p = 1;
	for (int i = 1;!a[i].second;i++) {
		if (c == n && (r & 1)) p = -1,r++;
		else if (c == 1 && !(r & 1)) p = 1,r++;
		else c += p;
	}
	cout<<r<<' '<<c;
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int n,m,a[105];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
		vec.push_back(a[i]);
	}
	sort(vec.begin(),vec.end());
	int rnk=lower_bound(vec.begin(),vec.end(),a[1])-vec.begin()+1;
	rnk=n*m-rnk+1;
	const int lie=(rnk+n-1)/n;
	cout<<lie<<' ';
	if(lie&1) cout<<(rnk-1)%n+1;
	else cout<<(n-(rnk-1)%n);
	return 0;
}


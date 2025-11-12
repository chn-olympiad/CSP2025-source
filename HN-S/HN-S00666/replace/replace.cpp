#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin)
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	srand(time(0));
	while(q--) {
		cout<<rand()%n<<'\n';
	}
	return 0;
}

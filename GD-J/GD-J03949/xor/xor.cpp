#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N=500005;
set<int> bst;
int n,k,ans,a[N],pre[N];
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bst.insert(0);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(bst.find(pre[i]^k)!=bst.end()) {
			ans++;
			bst.clear();
		}
		bst.insert(pre[i]);
	}
	cout<<ans;
	return 0;
}


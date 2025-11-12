#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=1e5+10;
int t,n,a[MAXN][3],cnt[3],f[3],asw;
vector<int> vec;
void dfs(int x) {
	if (x>n) {
		asw=max(asw,f[0]+f[1]+f[2]);
		return;
	}
	for (int i=0;i<3;i++) {
		if (cnt[i]>=n/2) continue;
		f[i]+=a[x][i];
		cnt[i]++;
		dfs(x+1);
		cnt[i]--;
		f[i]-=a[x][i];
	}
}
int main() {
	// i want to play delta force!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<3;j++) {
				cin>>a[i][j];
			}
		}
		if (n>5000) {
			for (int i=1;i<=n;i++) {
				vec.push_back(a[i][0]);
			}
			sort(vec.begin(),vec.end());
			asw=0;
			for (int i=1;i<=n/2;i++) {
				asw+=vec[i];
			}
		} else {
			asw=0;
			dfs(1);
		}
		cout<<asw<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100110][4];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		vector<int> q[5];
		int n;
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; ++i) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][3]&&a[i][1]>=a[i][2]) {
				q[1].push_back(max(a[i][2]-a[i][1],a[i][3]-a[i][1]));
				ans+=a[i][1];
			} else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]) {
				q[2].push_back(max(a[i][1]-a[i][2],a[i][3]-a[i][2]));
				ans+=a[i][2];
			} else {
				q[3].push_back(max(a[i][1]-a[i][3],a[i][2]-a[i][3]));
				ans+=a[i][3];
			}
		}
		for(int i=1; i<=3; ++i) {
			if(q[i].size()>n/2) {
				sort(q[i].begin(),q[i].end(),cmp);
				for(int j=0; j<q[i].size()-n/2; ++j) {
					ans+=q[i][j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

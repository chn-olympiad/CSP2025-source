#include<bits/stdc++.h>
using namespace std;
int t,n,kn,ans;
int a[100005][4];
vector<int> v[4];

void dfs(int k) {
	if(k==n+1) {
		ans=max(ans,v[1][0]+v[2][0]+v[3][0]);
//		printf("add:%d ans:%d 1:%d 2:%d 3:%d\n",v[1][0]+v[2][0]+v[3][0],ans,v[1][0],v[2][0],v[3][0]);
		return;
	}
	for(int p=1; p<=3; p++) {
		if(v[p].size()-1<kn) {
			v[p].push_back(k);
			v[p][0]+=a[k][p];
			dfs(k+1);
			v[p][0]-=a[k][p];
			v[p].pop_back();
		}

	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	v[1].push_back(0),v[2].push_back(0),v[3].push_back(0);
	while(t--) {
		cin>>n;
		ans=0,kn=n/2;
		for(int i=1; i<=n; i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1);
		cout <<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

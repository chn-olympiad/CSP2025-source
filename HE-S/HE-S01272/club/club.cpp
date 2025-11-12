#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int t,n,n2;
int a[N][4];

int dfs(int dep,int c1,int c2,int c3,int tans) {
	if(dep>n) {
		return tans;
	}
	int ans1,ans2,ans3;
	if(c1<n2) ans1=dfs(dep+1,c1+1,c2,c3,tans+a[dep][1]);
	if(c2<n2) ans2=dfs(dep+1,c1,c2+1,c3,tans+a[dep][2]);
	if(c3<n2) ans3=dfs(dep+1,c1,c2,c3+1,tans+a[dep][3]);
	return max(ans1,max(ans2,ans3));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	a[0][1]=a[0][2]=a[0][3]=0;
	cin>>t;
	while(t--) {
		cin>>n;
		n2=n/2;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(1,0,0,0,0)<<"\n";
	}
	return 0;
}

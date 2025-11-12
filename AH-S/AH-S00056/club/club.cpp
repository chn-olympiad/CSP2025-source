#include <bits/stdc++.h>
using namespace std;
int n,a[1000005][3],b[1000005];
int ans=0;
void dfs (int dep,int cnt1,int cnt2,int cnt3,int an){
	if (cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
	ans=max (ans,an);
	if (dep==n+1) return ;
	dfs (dep+1,cnt1+1,cnt2,cnt3,an+a[dep][0]);
	dfs (dep+1,cnt1,cnt2+1,cnt3,an+a[dep][1]);
	dfs (dep+1,cnt1,cnt2,cnt3+1,an+a[dep][2]);
}
void sol (){
	for (int i=1;i<=n;i++){
		b[i]=a[i][0];
	}
	sort (b+1,b+1+n);
	for (int i=n;i>=n/2+1;i--){
		ans+=b[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while (t--){
		bool ok=1;
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if (a[i][2]!=0||a[i][3]!=0) ok=0;
		}
		if (ok) {
			sol();
			continue;
		}
		dfs (1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 

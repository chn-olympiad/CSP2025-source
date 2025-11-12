#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[100005][4];
int box[4]; 
int anss=-1;
int n;
int hn;
void dfs(int u,int ans){
	if (u==n) {
		for (int i=1;i<=3;i++){
			if (box[i]+1<=hn){
				anss=max(anss,ans+dp[n][i]);
			//	cout<<anss;
			}
		}
		return;
	}
	for (int i=1;i<=3;i++){
		if (box[i]+1<=hn){
			box[i]++;
			dfs(u+1,ans+dp[u][i]);
			box[i]--;
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
void work(){
	cin>>n;
	hn=n/2;
	if (n>=200){
		vector<int>dpp(n);
		for (int i=0;i<n;i++) cin>>dpp[i];
		sort(dpp.begin(),dpp.end(),cmp);
		int ans=0;
		for (int i=0;i<n/2;i++){
			ans+=dpp[i];
		}
		cout<<ans<<"\n";
	}else{
		anss=0;
		for (int i=1;i<=n;i++){
			cin>>dp[i][1]>>dp[i][2]>>dp[i][3];
		}
		dfs(1,0);
		cout<<anss<<"\n";
	}

}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while (t--) work(); 
	return 0;
} 

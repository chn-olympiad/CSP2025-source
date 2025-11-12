#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn][3];
int cnt[3];
int ans,n,t;
void dfs(int k,int res){
	if(k==n){
		ans=max(ans,res);
		return;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]>=n/2)continue;
		cnt[i]++;
		dfs(k+1,res+a[k][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}

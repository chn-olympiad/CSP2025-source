#include<bits/stdc++.h>
using namespace std;
int n;
int a1[100005];
int a2[100005];
int a3[100005];
int ans=0;
void dfs(int cnt1,int cnt2,int cnt3,int s,int p){
	if(p>n){
		ans=max(ans,s);
		return ;
	}
	if(cnt1+1<=(n/2)) dfs(cnt1+1,cnt2,cnt3,s+a1[p],p+1);
	if(cnt2+1<=(n/2)) dfs(cnt1,cnt2+1,cnt3,s+a2[p],p+1);
	if(cnt3+1<=(n/2)) dfs(cnt1,cnt2,cnt3+1,s+a3[p],p+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
		ans=0;
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

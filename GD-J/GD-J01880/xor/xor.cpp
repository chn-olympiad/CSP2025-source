#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],f[1005][1005],dp[1005],ans=0;
vector<pair<int,int> >pos;
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first<y.first||(x.first==y.first&&x.second<y.second);
}
void dfs(int now,int ed,int cnt){
	ans=max(ans,cnt);
	for(int i=now;i<int(pos.size());i++){
		int l=pos[i].first,r=pos[i].second;
		if(l>ed) dfs(i+1,r,cnt+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=a[i];
		if(a[i]==k) pos.push_back({i,i});
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			f[i][j]=f[i][j-1]^a[j];
			if(f[i][j]==k) pos.push_back({i,j});
		}
	sort(pos.begin(),pos.end(),cmp);
	dfs(0,0,0);
	cout<<ans;
	fcloseall();
	return 0;
}

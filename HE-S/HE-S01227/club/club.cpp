#include<iostream>
using namespace std;
int a[1000001][4];
int cnt[4];
int n;int ans;
int dfs(int x,int y){
	if(x==n) return a[x][y];
	if(cnt[y]>=n/2) return -99;
	int ans=-2;
	for(int i=1;i<=3;i++){
		cnt[i]++;
		ans=max(ans,dfs(x+1,i));
		cnt[i]--;
	}
	return ans+a[x][y];
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++) ans=max(ans,dfs(1,i));
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

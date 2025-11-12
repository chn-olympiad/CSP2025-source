//GZ-S00057 毕节七星关东辰实验学校 刘杰 
#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int ji[4];
int ans;
void dfs(int w,int k,int z){
	if(w>k){
		ans=max(ans,z);return;
	}
	for(int i=1;i<=3;i++){
		if(ji[i]+1<=k/2){
			ji[i]++;
			dfs(w+1,k,z+a[w][i]);
			ji[i]--;
		}
	}
}
int solve(){
	memset(ji,0,sizeof(ji));
	ans=-1;int ck=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]==0&&a[i][3]==0){
			ck++;
		}
	}
	if(ck==n){
		//gets 5 pts!
		vector<int> p;
		for(int i=1;i<=n;i++){
			p.push_back(a[i][1]);
		}
		sort(p.begin(),p.end());ans=0;
		for(int i=n-1;i>=n/2;i--){
			ans+=p[i];
		}
	}
	else{
		//baoli
		//can get 20 pts!
		dfs(1,n,0);
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}

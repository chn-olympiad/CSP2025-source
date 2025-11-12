//GZ-S00235 遵义市南白初级中学 李灏家希
#include<bits/stdc++.h>
/*
	 
*/
using namespace std;
int t,n,ans=-1;
int cnt[4] = {0,0,0,0};
void dfs(vector< vector<int> > &a,int dep,int nums){
	if(dep>n) return;
	for(int j=1;j<=3;j++){
		if(cnt[j]+1>n/2) continue;
		cnt[j]++;
		//cout<<ans<<' '<<nums<<' '<<cnt[1]<<endl;
		dfs(a,dep+1,nums+a[dep][j]);
		cnt[j]--;
		if(dep==n){
			nums+=a[dep][j];
			if(nums>ans) ans=nums;
			nums-=a[dep][j];
		}
					
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	vector<int> aans;
	while(t--){
		cin>>n;
		vector<vector<int> > a(n+1,vector<int>(4)); 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(a,1,0);
		aans.push_back(ans);
		ans=0;
	}for(int i=0;i<aans.size();i++)	cout<<aans[i]<<endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],a[100005][4];
long long int ans=0;
int dfs(int tt,long long int l){
	if(tt>n){
		ans=max(ans,l);
		return 0;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(tt+1,l+a[tt][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int j=1;j<=n;j++){
			for(int y=1;y<=3;y++){
				cin>>a[j][y];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

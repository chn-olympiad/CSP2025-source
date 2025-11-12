#include<bits/stdc++.h>
using namespace std;
int n,a[100010][4],cnt[4];
long long ans;
void dfs(int num,long long sum){
	if(num==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		cnt[i]++;
		if(cnt[i]<=n/2)
			dfs(num+1,sum+a[num][i]);
		cnt[i]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
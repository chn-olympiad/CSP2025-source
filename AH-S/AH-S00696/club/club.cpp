#include <bits/stdc++.h>
using namespace std;
long long t,n,cnt[5],ma;
int a[100005][5];
void dfs(long long pos,long long sum){
	if(pos>n){
		ma=max(ma,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(pos+1,sum+a[pos][i]);
			cnt[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		ma=0;
		memset(cnt,0,sizeof(cnt));
		dfs(0,0);
		cout<<ma<<"\n";
	}
	return 0;
}

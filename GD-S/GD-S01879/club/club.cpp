#include<bits/stdc++.h>
using namespace std;
int T,n,t[4],a[110000][4],ans,td[110000];
void dfs(int now,int s){
	ans=max(s,ans);
	for(int i=1;i<=3;i++){
		if(t[i]+1<=n/2){
			t[i]++;
			dfs(now+1,s+a[now][i]);
			t[i]--;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n>=200){
			for(int i=1;i<=n;i++){
				td[i]=a[i][1];
			}
			sort(td+1,td+1+n);
			reverse(td+1,td+1+n);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=td[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}

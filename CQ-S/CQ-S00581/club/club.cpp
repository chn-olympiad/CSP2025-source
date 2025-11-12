#include<bits/stdc++.h>
#define int long long
using namespace std;
//operator
//priority
int a[500010][5];
int t,n,ans;
int maxx=-1;
int cnt[5];
void dfs(int x){
	if(x>n){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			ans+=a[x][i];
			dfs(x+1);
			cnt[i]--;
			ans-=a[x][i];
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,maxx=-1;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<maxx<<endl;
	}
	return 0;
}

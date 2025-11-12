#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[100010][4],maxx[100010],id[100010];
priority_queue<int> q[4];
signed main(){
//	system("fc club.out club4.ans"); return 0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			maxx[i]=id[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>maxx[i]){
					maxx[i]=a[i][j];
					id[i]=j;
				}
			}
			ans+=maxx[i];
			int x=1e9;
			for(int j=1;j<=3;j++){
				if(j==id[i]) continue;
				x=min(x,maxx[i]-a[i][j]);
			}
			q[id[i]].push(-x);
		}
		for(int i=1;i<=3;i++){
			while(q[i].size()>n/2){
				int x=q[i].top(); q[i].pop();
				ans+=x;
			}
		}
		cout<<ans<<'\n';	
	}
	return 0;
}

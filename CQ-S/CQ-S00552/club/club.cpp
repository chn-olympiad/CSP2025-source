#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct e{
	int x,y,z;
	operator < (const e& o) const{
		return x<o.x;
	}
};
int t,n,a[N][4],cnt[4],vis[N],ans;
priority_queue <e> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			q.push(e{a[j][1],j,1});q.push(e{a[j][2],j,2});q.push(e{a[j][3],j,3});
		}
		while(!q.empty()){
			e u=q.top();
			q.pop();
			if(!vis[u.y]&&cnt[u.z]<(n/2)){
				ans+=u.x;
				vis[u.y]=1;
				cnt[u.z]++;
				
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

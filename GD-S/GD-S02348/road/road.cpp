#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[20004],ans,cnt,cnt2,vis[20004],c[20004],sum[20004];
struct Node{
	int x,y,w,ad;
};
vector<Node> e;
priority_queue<pair<int,pair<int,int>>> q;
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]); 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n+20;i++){
		f[i]=i;
	}
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		q.push({-w,{u,v}});
	}
	if(k==0){
		while(cnt!=n-1){
			int u=q.top().second.first,v=q.top().second.second,w=q.top().first*(-1);
			q.pop();
			int uu=find(u),vv=find(v);
			if(uu!=vv){
				ans+=w;
				cnt++;
				f[uu]=vv;
			}
		}
		cout << ans << endl;
		return 0;
	}
	for(int i = n+1;i <= n+k;i++){
		cin>> c[i];
		for(int j = 1;j <= n;j++){
			int w;
			cin >> w;
			q.push({(-w-c[i]),{i,j}});
		}
	}
	int tmp=n;
//	cout << q.size() << endl;
	while(cnt!=tmp-1&&q.size()){
//		cout << cnt << " " << q.size()<< endl;
		int u=q.top().second.first,v=q.top().second.second,w=q.top().first*(-1);
		q.pop();
		int uu=find(u),vv=find(v);
		if(uu!=vv){
			ans+=w;
			cnt++;
			if(u>n&&vis[u]>0){
				vis[u]++;
				ans-=c[u];
			}
			if(u>n&&vis[u]==0){
				vis[u]=1;
				tmp++;
				sum[u]+=w; 
			}
			f[uu]=vv;
		}
	}
	for(int i = n+1;i <= n+k;i++){
		if(vis[i]==1){
			ans-=sum[i];
		}
	}
	cout << ans << endl;
	return 0;
}

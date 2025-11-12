#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
bool vis[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3],vis[i]=0;
		vector<int>p[4];
		priority_queue<pair<int,int>>q[4];
		int sum=0;
		for(int i=1;i<=n;i++){
			int maxn=max({a[i][1],a[i][2],a[i][3]});
			sum+=maxn;
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxn){
					p[j].push_back(i);
					if(j!=1)q[j].push({a[i][1]-a[i][j],i});
					if(j!=2)q[j].push({a[i][2]-a[i][j],i});
					if(j!=3)q[j].push({a[i][3]-a[i][j],i});
				}
			}
		}
		for(int j=1;j<=3;j++){
			if(p[j].size()>n/2){
				int cnt=p[j].size();
				while(cnt>n/2){
					if(!vis[q[j].top().second]){
						vis[q[j].top().second]=1;
						sum+=q[j].top().first;
						cnt--;
					}
					q[j].pop();
				}
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

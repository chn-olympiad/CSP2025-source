#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][4],b[10],ans;
priority_queue<int,vector<int>,greater<int> >q[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		b[1]=b[2]=b[3]=ans=0;
		for(int i=1;i<=n;i++){
			int maxx=0,id=0,mx=0,id1=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>=maxx){
					mx=maxx;
					id1=id;
					maxx=a[i][j];
					id=j;
				}
				else if(a[i][j]>=mx){
					mx=a[i][j];
					id1=j;
				}
			}
			q[id].push(maxx-mx);
			b[id]++;
			ans+=maxx;
		}
		for(int i=1;i<=3;i++){
			while(b[i]>n/2){
				ans-=q[i].top();
				q[i].pop();
				b[i]--;
			}
		}
		cout<<ans<<endl;
	}
}

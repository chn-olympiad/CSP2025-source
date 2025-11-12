#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],T;
long long ans;
priority_queue<int> q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
		ans=0;
		cin>>n;
		int mx=n/2;
		for(int i=1;i<=n;i++){
			int mx1=0, mx2=0, mx1id=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx1){
					mx2=mx1;
					mx1=a[i][j];
					mx1id=j;
				}else if(a[i][j]>mx2) mx2=a[i][j];
			}
			ans+=mx1;
			q[mx1id].emplace(mx2-mx1);
		}
		for(int i=1;i<=3;i++){
			while(q[i].size()>mx){
				ans+=q[i].top();
				q[i].pop();
			}
		}
		cout<<ans<<'\n';
	}
}

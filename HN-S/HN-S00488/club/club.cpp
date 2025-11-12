#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
priority_queue<int> q[3];
int T,n,ans,a[3][100005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++){
			while(!q[i].empty()) q[i].pop();
		}
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			int maxn=max({a[0][i],a[1][i],a[2][i]});
			ans+=maxn;
			int j=0;
			for(j=0;j<3;j++){
				if(a[j][i]==maxn){
					swap(a[j][i],a[2][i]);
					break;
				}
			}
			if(a[1][i]<a[0][i]) swap(a[1][i],a[0][i]);
			q[j].push(a[1][i]-a[2][i]);
		}
		for(int i=0;i<3;i++){
			while(q[i].size()>n/2){
				ans+=q[i].top();
				q[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 

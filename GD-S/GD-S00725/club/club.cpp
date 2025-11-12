#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
using ll = long long;
struct node{
	int x,y,z;
}a[maxn];
int m[maxn];
vector<int>e[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		ll ans=0ll;
		e[0].clear();
		e[1].clear();
		e[2].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(x>=y and x>=z) e[0].push_back(i),ans+=x;
			else if(y>=x and y>=z) e[1].push_back(i),ans+=y;
			else if(z>=y and z>=x) e[2].push_back(i),ans+=z;
		}
		if((int)(e[0].size())<=n/2 and (int)(e[1].size())<=n/2 and (int)(e[2].size())<=n/2) cout<<ans<<"\n";
		else{
			int index=0,len;
			if((int)(e[0].size())>n/2){
				len=e[0].size()-(n/2);
				for(auto u:e[0]){
					int x=a[u].x,y=a[u].y,z=a[u].z;
					m[++index]=min(x-y,x-z);
				}
			}
			else if((int)(e[1].size())>n/2){
				len=e[1].size()-(n/2);
				for(auto u:e[1]){
					int x=a[u].x,y=a[u].y,z=a[u].z;
					m[++index]=min(y-x,y-z);
				}
			}
			else if((int)(e[2].size())>n/2){
				len=e[2].size()-(n/2);
				for(auto u:e[2]){
					int x=a[u].x,y=a[u].y,z=a[u].z;
					m[++index]=min(z-x,z-y);
				}
			}
			sort(m+1,m+1+index);
			for(int i=1;i<=len;i++) ans-=m[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}

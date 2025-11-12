#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
struct node{
	int id,k;
}a[N][3];
struct Node{
	int x,y,z;
	bool operator<(const Node&a)const{
		return z>a.z;
	}
};
priority_queue<Node> q[4];
int n,t,c[4],ans;
inline bool cmp(node x,node y){
	return x.k>y.k;
}
inline void solve(){
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	c[1]=c[2]=c[3]=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].k;
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+3+1,cmp);
		int o=a[i][1].id;
		c[o]++,ans+=a[i][1].k;
		q[o].push({o,a[i][2].id,a[i][1].k-a[i][2].k});
		if(c[o]>n/2){
			Node tmp=q[o].top();
			q[o].pop();
			ans-=tmp.z;
			c[o]--,c[tmp.y]++;
			q[tmp.y].push({tmp.y,tmp.x,-tmp.z}); 
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 

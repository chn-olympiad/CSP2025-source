#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct Node{
	int id,x;
}b[5];
ll a[N][5],n,c[N],ans,tot,p[N];
bool vis[N];
inline bool cmp(Node x,Node y){
	return x.x>y.x;
}
inline void solve(){
	cin>>n;
	c[1]=c[2]=c[3]=0; ans=0; tot=0;
	for(int i=1;i<=n;i++) vis[i]=0,c[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	priority_queue<ll> q[5];
	for(int i=1;i<=n;i++){
		b[1].id=1,b[1].x=a[i][1];
		b[2].id=2,b[2].x=a[i][2];
		b[3].id=3,b[3].x=a[i][3];
		sort(b+1,b+1+3,cmp);
		if(c[b[1].id]<n/2){
			ans+=b[1].x; c[b[1].id]++; p[i]=b[1].id;
			q[b[1].id].push(-b[1].x+b[2].x); // a1 a3
		}else{
			ll x=q[b[1].id].top();
			ll tmp=x+b[1].x;
			if(tmp>b[2].x){
				q[b[1].id].pop();
				q[b[1].id].push(-b[1].x+b[2].x);
				ans+=tmp;
			}else{
				ans+=b[2].x;
				c[b[2].id]++;
			}
		}
	}
	cout<<ans<<'\n'; //147325
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}
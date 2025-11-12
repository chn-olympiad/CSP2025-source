#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
template<typename T> bool read(T&x){x=0;T f=1;char c=getchar();while((c<'0'||c>'9')&&c!=EOF){if(c=='-') f=-1;c=getchar();}if(c==EOF) return 0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return 1;}
template<typename T,typename ...T1> bool read(T&x,T1&...y){return read(x)+read(y...);}
const int N=1e5+15,M=5e4+15;
using namespace std;

int n,m,a[N][3],ans;
struct node{
	int id,x,y;
	bool operator < (node b)const{
		return max(x,y)<max(b.x,b.y);
	}
};
priority_queue<node> q[3];

void solve(){
	read(n);m=n>>1;ans=0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	rep(i,1,n){
		read(a[i][0],a[i][1],a[i][2]);
		if(a[i][0]>=max(a[i][1],a[i][2])){
			if(q[0].size()<m) q[0].push({i,a[i][1]-a[i][0],a[i][2]-a[i][0]}),ans+=a[i][0];
			else{
				auto v=q[0].top();
				if(ans+max(v.x,v.y)+a[i][0]<ans+max(a[i][1],a[i][2])){
					if(a[i][1]>=a[i][2]) q[1].push({i,a[i][0]-a[i][1],a[i][2]-a[i][1]}),ans+=a[i][1];
					else q[2].push({i,a[i][0]-a[i][2],a[i][1]-a[i][2]}),ans+=a[i][2];
				}else{
					ans+=max(v.x,v.y)+a[i][0];
					q[0].pop();q[0].push({i,a[i][1]-a[i][0],a[i][2]-a[i][0]});
					if(a[v.id][1]>=a[v.id][2]) q[1].push({v.id,a[v.id][0]-a[v.id][1],a[v.id][2]-a[v.id][1]});
					else q[2].push({v.id,a[v.id][0]-a[v.id][2],a[v.id][1]-a[v.id][2]});
				}
			}
		}else if(a[i][1]>=a[i][2]){
			if(q[1].size()<m) q[1].push({i,a[i][0]-a[i][1],a[i][2]-a[i][1]}),ans+=a[i][1];
			else{
				auto v=q[1].top();
				if(ans+max(v.x,v.y)+a[i][1]<ans+max(a[i][0],a[i][2])){
					if(a[i][0]>=a[i][2]) q[0].push({i,a[i][1]-a[i][0],a[i][2]-a[i][0]}),ans+=a[i][0];
					else q[2].push({i,a[i][0]-a[i][2],a[i][1]-a[i][2]}),ans+=a[i][2];
				}else{
					ans+=max(v.x,v.y)+a[i][1];
					q[1].pop();q[1].push({i,a[i][0]-a[i][1],a[i][2]-a[i][1]});
					if(a[v.id][0]>=a[v.id][2]) q[0].push({v.id,a[v.id][1]-a[v.id][0],a[v.id][2]-a[v.id][0]});
					else q[2].push({v.id,a[v.id][0]-a[v.id][2],a[v.id][1]-a[v.id][2]});
				}
			}
		}else{
			if(q[2].size()<m) q[2].push({i,a[i][0]-a[i][2],a[i][1]-a[i][2]}),ans+=a[i][2];
			else{
				auto v=q[2].top();
				if(ans+max(v.x,v.y)+a[i][2]<ans+max(a[i][0],a[i][1])){
					if(a[i][0]>=a[i][1]) q[0].push({i,a[i][1]-a[i][0],a[i][2]-a[i][0]}),ans+=a[i][0];
					else q[1].push({i,a[i][0]-a[i][1],a[i][2]-a[i][1]}),ans+=a[i][1];
				}else{
					ans+=max(v.x,v.y)+a[i][2];
					q[2].pop();q[2].push({i,a[i][0]-a[i][2],a[i][1]-a[i][2]});
					if(a[v.id][0]>=a[v.id][2]) q[0].push({v.id,a[v.id][1]-a[v.id][0],a[v.id][2]-a[v.id][0]});
					else q[1].push({v.id,a[v.id][0]-a[v.id][1],a[v.id][2]-a[v.id][1]});;
				}
			}
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;read(T);
	while(T--) solve();
	return 0;
}
/*
T3,T4 感觉没法做（
T1 感觉像反悔贪心来着。
*/
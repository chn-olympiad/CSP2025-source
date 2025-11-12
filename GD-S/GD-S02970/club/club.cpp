#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
bool MB1;
const int N=1e5+10;
int n;
int a[N][4];
struct cmp{
	bool operator()(const P &x,const P &y){
		return x.first<y.first;
	}
};
priority_queue<P,vector<P>,cmp> q[4];
int res[4];
void solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=3;i++) while(q[i].size()) q[i].pop();
	res[1]=res[2]=res[3]=n/2;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		int ma=-1,id=0;
		int nma=-1,nid=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]>ma) ma=a[i][j],id=j;
		}
		for(int j=1;j<=3;j++){
			if(j==id) continue;
			if(a[i][j]>nma) nma=a[i][j],nid=j;
		}
		if(res[id]){
			ans+=ma,q[id].push({-ma+nma,i});res[id]--;
		}
		else{	
			int d1=ma+q[id].top().first,d2=nma;
			if(d1>d2){
				int did=q[id].top().second;q[id].pop();
				q[id].push({-ma+nma,i});
				ans+=d1;
			}
			else{
				ans+=d2;
			}
		}
	}
	cout<<ans<<endl;
	/*for(int i=1;i<=n/2;i++) q.push({-a[i][1],i}),ans+=a[i][1];
	for(int i=n/2+1;i<=n;i++){
		int x=q.top().first,y=q.top().second;q.pop();
		int ma=max(ma,a[i][2],a[i][3]);
		if(ma>x+a[i][1]) ans+=ma,q.push({x,y});
		else ans+=x+a[i][1],q.push({-a[i][1]});
	}*/
}

bool MB2;
void start(){
	#ifdef GNF
	freopen("1.in","r",stdin);
	#endif
}
void end(){
	cerr<<endl;
	cerr<<fixed<<setprecision(3)<<clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	cerr<<abs(&MB2-&MB1)/1024.0/1024.0<<"MB"<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	start();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--) solve();

	end();
}


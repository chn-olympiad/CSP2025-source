//15 21
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5,M=1e6+5,K=10+5,E=2e6+5,P=2e4+5;
//for(;;)++rp;
int n,m,k,c[N],a[K][N],fa[P];
bool vis[N];
struct node{
	int u,v,w;
}e[M],r[E],tmp[E];
struct n2{
	int to,val;
	bool operator<(const n2 &o)const{
		return val>o.val;
	}
};
vector<n2> rnr[N],nbr[N];
priority_queue<n2> q;
void clq(){
	priority_queue<n2> t;
	swap(q,t);
	return;
}
void ms(int a,int b){
	for(int i=1;i<=a;i++){
		r[i]=e[i];
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		r[i]=e[i];
		rnr[e[i].u].push_back({e[i].v,e[i].w});
		rnr[e[i].v].push_back({e[i].u,e[i].w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int mini=1e18;
	//0-index and 1-index, yay
	for(int i=0;i<(1<<k);i++){
//		cerr<<"$"<<i<<" "<<(1<<k)<<endl;
		int rc=m,ans=0;
		for(int i=1;i<=n+k+1;i++){
			nbr[i].clear();
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				for(int l=1;l<=n;l++){
					r[++rc]={n+j+1,l,a[j][l]};
					nbr[l].push_back({n+j+1,a[j][l]});
					nbr[n+j+1].push_back({l,a[j][l]});
//					cerr<<"#"<<j<<endl;
				}
				ans+=c[j];
			}
		}
		ms(m,rc);
		for(int j=1;j<=n+k+1;j++){
			vis[j]=false;
		}
		clq();
		q.push({1,0});
		while(!q.empty()){
			n2 cn=q.top();
			q.pop();
			int cur=cn.to,val=cn.val;
			if(vis[cur]){
				continue;
			}
			ans+=val;
			vis[cur]=true;
			for(n2 nxtn:nbr[cur]){
				int nxt=nxtn.to,w=nxtn.val;
				if(!vis[nxt]){
					q.push({nxt,w});
				}
			}
			for(n2 nxtn:rnr[cur]){
				int nxt=nxtn.to,w=nxtn.val;
				if(!vis[nxt]){
					q.push({nxt,w});
				}
			}
		}
		//In fact, I didn't write Prim before.
		mini=min(mini,ans);
//		cerr<<"@"<<i<<" "<<ans<<endl;
	}
	cout<<mini;
	//U r still outputing wrong answers!
	//What r u doing?!
	return 0;
}
//k<=10, that's great!
//This is wangboyue_740325@Luogu.
//I'm so shabby that I didn't notice Xiangzhen!=Chengshi.
//The machine I'm using is too slow!
//It used 35.69 sec to output road2.
//Ohno, my kruskel!
//Why is 1000 times 1e6 log 1e6 so slow???

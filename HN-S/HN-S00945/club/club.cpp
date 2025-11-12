#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,y,z;
}a[100005];
vector<node> t;
bool vis[100005];
priority_queue<int> rp[5];
long long ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	// int st=clock();
	cin>>T;
	while(T--){
		ans=0;
		t.clear();
		// rp[1].clear(),rp[2].clear(),rp[3].clear();
		while(!rp[1].empty()) rp[1].pop();
		while(!rp[2].empty()) rp[2].pop();
		while(!rp[3].empty()) rp[3].pop();
		cin>>n;
		for(int i=1;i<=n;i++)
			vis[i]=false;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			t.push_back({a[i].x,i,1});
			t.push_back({a[i].y,i,2});
			t.push_back({a[i].z,i,3});
		}
		sort(t.begin(),t.end(),[](node x,node y){return x.x>y.x;});
		for(node v:t){
			if(vis[v.y]) continue;
			if(rp[v.z].size()==n/2){
				int vl=v.x+rp[v.z].top();
				if(v.z==1&&vl<=max(a[v.y].y,a[v.y].z)) continue;
				if(v.z==2&&vl<=max(a[v.y].x,a[v.y].z)) continue;
				if(v.z==3&&vl<=max(a[v.y].x,a[v.y].y)) continue;
				vis[v.y]=true;
				ans+=v.x+rp[v.z].top();
				rp[v.z].pop();
				int rv;
				if(v.z==1)
					rv=max(a[v.y].y,a[v.y].z)-v.x;
				if(v.z==2)
					rv=max(a[v.y].x,a[v.y].z)-v.x;
				if(v.z==3)
					rv=max(a[v.y].x,a[v.y].y)-v.x;
				// cout<<"RV:"<<rv<<endl;
				rp[v.z].push(rv);
			}
			else{
				vis[v.y]=true;
				ans+=v.x;
				int rv;
				if(v.z==1)
					rv=max(a[v.y].y,a[v.y].z)-v.x;
				if(v.z==2)
					rv=max(a[v.y].x,a[v.y].z)-v.x;
				if(v.z==3)
					rv=max(a[v.y].x,a[v.y].y)-v.x;
				rp[v.z].push(rv);
			}
		}
		cout<<ans<<'\n';
	}
	// cout<<clock()-st<<"/"<<CLOCKS_PER_SEC;
	return 0;
}
/*
14:35 start
dp?
seems like greedy
nope
fanhui tanxing()
sab ti
限制意味着最多只会有一个满员的
14:54 guale
dayangliguole,xiayangliguale??????
its nonsense
i have wasted 30 min
15:08 AC
SO EASY
stop playing maimai
我常常追忆过去，后面忘了
wtf tle 1.08?????????
im somebody.not open O2
i wants to play arcaea,phigros,maimai,genshin,honkai starrail,zzz,ba,arknight
//freopen
#define int long long
maybe i will afo after NOIP
luogu:766913
*/
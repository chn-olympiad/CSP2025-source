#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define endl '\n'
using namespace std;
constexpr int N=1e5+10;
int n,m,a[N][3];
int cnt[3];
bool used[N][3];
ll ans;
priority_queue<pii>heap;
priority_queue<int>heapa,heapb;
pii get(int x){
	return (x<=n)?mp(x,1):mp(x-n,2);
}
void solve(){
	cin>>n;
	m=n>>1;
	ans=0;
	cnt[0]=n,cnt[1]=0,cnt[2]=0;
	priority_queue<pii>emt;
	swap(heap,emt);
	priority_queue<int>em,emm;
	swap(heapa,em);
	swap(heapb,emm);
	for(int i=1;i<=n;i++){
		used[i][0]=1;
		used[i][1]=used[i][2]=0;
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		ans+=a[i][0];
		heap.push(mp(a[i][1]-a[i][0],i));
		heap.push(mp(a[i][2]-a[i][0],i+n));
	}
	while(heap.size()&&(cnt[1]<=m||cnt[2]<=m)){
		pii t=heap.top();
		pii u=get(t.second);
		heap.pop();
		if(cnt[u.second]==m|| !used[u.first][0])continue;
		if(cnt[0]<=m&&t.first<=0)break;
		ans+=t.first;
		cnt[0]--;
		cnt[u.second]++;
		used[u.first][u.second]=1;
		used[u.first][0]=0; 
	}
	if(cnt[1]==m||cnt[2]==m){
		if(cnt[1]==cnt[2])return cout<<ans<<endl,void();
		if(cnt[1]==m){
			for(int i=1;i<=n;i++){
				if(used[i][1])heapa.push(max(a[i][2]-a[i][1],a[i][0]-a[i][1]));
				else if(used[i][0])heapb.push(a[i][1]-a[i][0]);
				else heapb.push(a[i][1]-a[i][2]);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(used[i][2])heapa.push(max(a[i][1]-a[i][2],a[i][0]-a[i][2]));
				else if(used[i][0])heapb.push(a[i][2]-a[i][0]);
				else heapb.push(a[i][2]-a[i][1]);
			}
		}
		while(heapa.size()&&heapb.size()){
			int t=heapa.top()+heapb.top();
			heapa.pop();
			heapb.pop();
			if(t<=0)break;
			ans+=t;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("club.out","w",stdout);
	int _T;
	cin>>_T;
	while(_T--)
		solve();
	
	
	
	
	return 0;
}

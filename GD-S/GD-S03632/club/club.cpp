#include<iostream>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
const int N=1e5+5;

struct tobe{
	int i,k;
	bool operator<(tobe it)const{
		return k>it.k;
	}
};

struct node{
	int pos;
	tobe f[5];
	void in(){
		cin>>f[1].k>>f[2].k>>f[3].k;
		for(int i=1;i<=3;i++){
			f[i].i=i;
		}
		sort(f+1,f+4);
	}
	bool operator<(node it)const{
		return f[1].k-f[2].k>it.f[1].k-it.f[2].k;
	}
};

node a[N];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].in();
	}
	priority_queue<node>heap[5];
	for(int i=1;i<=n;i++){
		a[i].pos=1;
		heap[a[i].f[1].i].push(a[i]);
	}
	for(int i=1;i<=3;i++){
		while(heap[i].size()>n/2){
			node x=heap[i].top();
			heap[i].pop();
			x.pos=2;
			heap[x.f[2].i].push(x);
		}
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		while(!heap[i].empty()){
			node x=heap[i].top();
			heap[i].pop();
			ans+=x.f[x.pos].k;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	#else
		freopen("club5.in","r",stdin);
		freopen("club5.out","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}

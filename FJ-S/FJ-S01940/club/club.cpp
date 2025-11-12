#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
bool Mbe;

int a[N][3];
int bst[N];

void fake_main(){
	priority_queue<int>b[3]; int cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	int ans=0;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		int mx=max(max(a[i][0],a[i][1]),a[i][2]);
		if(mx==a[i][0]){
			bst[i]=0; b[bst[i]].push(max(a[i][1],a[i][2])-mx);
		}else if(mx==a[i][1]){
			bst[i]=1; b[bst[i]].push(max(a[i][0],a[i][2])-mx);
		}else{
			bst[i]=2; b[bst[i]].push(max(a[i][0],a[i][1])-mx);
		}
		cnt[bst[i]]++; ans+=mx;
	}
	
	if(cnt[0]>n/2){
		while(cnt[0]>n/2){
			ans+=b[0].top();
			b[0].pop(); cnt[0]--;
		}
	}else if(cnt[1]>n/2){
		while(cnt[1]>n/2){
			ans+=b[1].top();
			b[1].pop(); cnt[1]--;
		}
	}else if(cnt[2]>n/2){
		while(cnt[2]>n/2){
			ans+=b[2].top();
			b[2].pop(); cnt[2]--;
		}
	}
	
	cout<<ans<<"\n";
}

/*
1 4
0 1 0
0 1 0 
0 2 0
0 2 0
*/

bool Med;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cerr<<fabs(&Med-&Mbe)/1028576.0<<"MB\n";
	int t; cin>>t;
	while(t--) fake_main();
	cerr<<clock()*1.0/CLOCKS_PER_SEC*1000.0<<"ms\n";
}


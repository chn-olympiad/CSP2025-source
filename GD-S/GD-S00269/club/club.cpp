#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define int long long
#define pii pair<int,int>
#define x first
#define y second
const int N=2e5+10;
int n,s[N];
pii a[N][4];
bool cmp(pii a,pii b){
	return a.x>b.x;
}
vector<int> d;
void solve(){
	cin>>n;
	rep(j,1,3) s[j]=0;
	int ans=0;
	rep(i,1,n){
		rep(j,1,3) cin>>a[i][j].x,a[i][j].y=j;
		sort(a[i]+1,a[i]+3+1,cmp);
		s[a[i][1].y]++,ans+=a[i][1].x;
	}
	d.clear();
	rep(i,1,n) if(s[a[i][1].y]>n/2) d.push_back(a[i][1].x-a[i][2].x);
	sort(d.begin(),d.end());
	rep(i,1,3){
		if(s[i]>n/2){
			for(int j=0;j<(s[i]-n/2);++j) ans-=d[j]; 
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) solve();	
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

*/

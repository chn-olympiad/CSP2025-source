#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10;
const int M=3e5+10;
int n,a[N][4];
bool vis[M];
struct Node{
	int x,y,z;
}t[M];
bool cmp(Node X,Node Y){
	return X.z>Y.z;
}
void clear(){
	for(int i=0;i<=M-5;i++){
		vis[i]=0;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		t[3*i-2]={1,i,a[i][1]-max(a[i][2],a[i][3])};
		t[3*i-1]={2,i,a[i][2]-max(a[i][1],a[i][3])};
		t[3*i-0]={3,i,a[i][3]-max(a[i][1],a[i][2])};
	}
	
	sort(t+1,t+1+3*n,cmp);
	
	int cnt[4]={0,0,0,0},ans=0;
	for(int i=1;i<=3*n;i++){
		if(cnt[t[i].x]<n/2&&!vis[t[i].y]){
//			cout<<t[i].x<<" "<<t[i].y<<" "<<t[i].z<<"\n";
			
			ans+=a[t[i].y][t[i].x];
			cnt[t[i].x]++,vis[t[i].y]=1;
		}
	}
	
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;cin>>T;
	
	while(T--){
		clear();
		solve();
	}
	
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

*/

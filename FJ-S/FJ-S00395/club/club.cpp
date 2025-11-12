#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int a[100010][4];
int tmp[4]; 
int n;
struct node{
	int st,ed;
	int i;
}b[100010];
node get(int i){
	node re;
	int maxn = 0;
	for(int j = 1;j<=3;j++){
		if(maxn<a[i][j]){
			maxn = a[i][j];
			re.st = j;
		}
	}
	maxn = 0;
	for(int j = 1;j<=3;j++){
		if(maxn<a[i][j] && j != re.st){
			maxn = a[i][j];
			re.ed = j;
		}
	}
	re.i = i;
	return re;
}
bool cmp(node x,node y){
	return a[x.i][x.st]-a[x.i][x.ed] > a[y.i][y.st]-a[y.i][y.ed];
}
int cnt[4];
void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		}
		b[i] = get(i);
	}
	sort(b+1,b+n+1,cmp);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(cnt[b[i].st] < n/2){
			cnt[b[i].st]++;
			ans += a[b[i].i][b[i].st];
		}else{
			cnt[b[i].ed]++;
			ans += a[b[i].i][b[i].ed];
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		for(int i = 1;i<=3;i++)cnt[i] = 0;
		solve();
	}
}

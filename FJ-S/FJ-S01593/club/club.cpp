#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
const int N=1e5+5;
int T,n;
pii a[N][5];
void solve(){
	cin>>n;
	int ans=0;
	priority_queue<int> q[5];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].fs;
			a[i][j].sc=j;
		}
		sort(a[i]+1,a[i]+4);
//		for(int j=1;j<=3;j++)
//			cout<<a[i][j].fs<<' '<<a[i][j].sc<<' ';
//		cout<<'\n';
		ans+=a[i][3].fs;
		q[a[i][3].sc].push(-a[i][3].fs+a[i][2].fs);
	}
	for(int i=1;i<=3;i++){
		while(q[i].size()>n/2){
			ans+=q[i].top();
			q[i].pop();
		}
	}
	cout<<ans<<'\n';
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
		solve();
	return 0;
}
//14:30-14:50

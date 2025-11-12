#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct P{
	int id,rel;
};
int t,n;

bool cmp(P a,P b){
	return a.rel>b.rel;
}
void solve(){
int vis[N];
vector<P> w[5];
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int v;
			cin>>v;
			w[j].push_back({i,v});
		}
		for(int j=1;j<=3;j++) sort(w[j].begin(),w[j].end(),cmp);
	}
	int a=0,b=0,c=0,s1=0,s2=0,s3=0;
	int cnt=0;
	while(cnt<=n){
		while(a<w[1].size() and vis[w[1][a].id]) a++;
		while(b<w[2].size() and vis[w[2][b].id]) b++;
		while(c<w[3].size() and vis[w[3][c].id]) c++;
		int n1=w[1][a].rel,n2=w[2][b].rel,n3=w[3][c].rel;
		cnt++;
		if(a<w[1].size() and s1<=n/2 and n1>=n2 and n1>=n3){
			ans+=n1;
			a++;s1++;
			vis[w[1][a].id]++;
			continue;
		}
		if(b<w[2].size() and s2<=n/2 and n2>=n1 and n2>=n3){
			ans+=n2;
			b++;s2++;
			vis[w[2][b].id]++;
			continue;
		}
		if(c<w[3].size() and s3<=n/2 and n3>=n1 and n3>=n2){
			ans+=n3;
			c++;s3++;
			vis[w[3][c].id]++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}

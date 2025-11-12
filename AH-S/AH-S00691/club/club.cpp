#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=1e5+5;
using namespace std;
pair <int,ll> a[5][MAXN];
bool vis[MAXN];
struct node{
	ll f;
	int s;
	int id;
	int y;
}b[MAXN*3];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	int n;
	cin>>T;
	while(T--){
		cin>>n;
		int mid=n>>1;
		int pos=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i].first;
			}
			a[1][i].second=a[1][i].first-a[2][i].first-a[3][i].first;
			a[2][i].second=a[2][i].first-a[1][i].first-a[3][i].first;
			a[3][i].second=a[3][i].first-a[1][i].first-a[2][i].first;
			b[pos].f=a[1][i].second;
			b[pos].y=a[1][i].first;
			b[pos].id=1;
			b[pos++].s=i;
			b[pos].f=a[2][i].second;
			b[pos].y=a[2][i].first;
			b[pos].id=2;
			b[pos++].s=i;
			b[pos].f=a[3][i].second;
			b[pos].y=a[3][i].first;
			b[pos].id=3;
			b[pos++].s=i;
		}
		memset(vis,0,sizeof(vis));
		sort(b+1,b+1+3*n,cmp);
		ll ans=0;
		int tp=n;
		int j=1;
		int d[5];
		memset(d,0,sizeof(d));
		while(tp){
			if(!vis[b[j].s]&&d[b[j].id]<mid){
				vis[b[j].s]=1;
				ans+=b[j].y;
				d[b[j].id]++;
				tp--;
			}
			j++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

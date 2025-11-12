#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int T;
int n;
ll a[N][5],ans;
struct node{
	ll s;
	int w;
}b[N][5];
priority_queue<pair<ll,int> > q[4];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		while(q[3].size()) q[3].pop();
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i][1].s=a[i][1];
			b[i][2].s=a[i][2];
			b[i][3].s=a[i][3];
			b[i][1].w=1;
			b[i][2].w=2;
			b[i][3].w=3;
			sort(b[i]+1,b[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			int h=b[i][1].w;
			if((int)q[h].size()<n/2){
				q[h].push({b[i][2].s-b[i][1].s,i});
				ans+=b[i][1].s;
			}
			else{
				if(q[h].top().first+b[i][1].s>b[i][2].s){
					ans+=q[h].top().first+b[i][1].s;
					int x=q[h].top().second;
					q[h].pop();
					q[b[x][2].w].push({b[x][3].s-b[x][2].s,x});
					q[h].push({b[i][2].s-b[i][1].s,i});
				}
				else{
					ans+=b[i][2].s;
					q[b[i][2].w].push({b[i][1].s-b[i][2].s,i});
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

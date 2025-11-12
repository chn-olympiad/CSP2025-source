#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=1e5+5;
int n;
struct node{
	int a,b,ta,tb; 
}p[N];
priority_queue<pair<int,int> > q[3];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int mn=min({x,y,z});
		if(mn==x){
			if(y>z) p[i].a=y,p[i].b=z,p[i].ta=1,p[i].tb=2;
			else p[i].a=z,p[i].b=y,p[i].ta=2,p[i].tb=1;
		}
		else if(mn==y){
			if(x>z) p[i].a=x,p[i].b=z,p[i].ta=0,p[i].tb=2;
			else p[i].a=z,p[i].b=x,p[i].ta=2,p[i].tb=0;
		}
		else{
			if(x>y) p[i].a=x,p[i].b=y,p[i].ta=0,p[i].tb=1;
			else p[i].a=y,p[i].b=x,p[i].ta=1,p[i].tb=0;
		}
//		cout<<a[i].a<<" "<<a[i].ta<<" | "<<a[i].b<<" "<<a[i].tb<<"\n";
	}
	int ans=0;
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	for(int i=1;i<=n;i++){
		int a=p[i].a,b=p[i].b,ta=p[i].ta,tb=p[i].tb;
		if((int)q[ta].size()<n/2){
			q[ta].push({b-a,i});
			ans+=a;
		}
		else{
			if(b-a<q[ta].top().first){
				int j=q[ta].top().second;
				q[ta].pop();
				q[ta].push({b-a,i});
				ans=ans-p[j].a+p[i].a+p[j].b;
			}else{
				ans+=p[i].b;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main(){
//	freopen("club5.in","r",stdin);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T; cin>>T;
	while(T--) solve();
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

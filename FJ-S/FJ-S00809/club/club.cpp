#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=1e5+10; 
int T,n;
int a[N][3];

struct node{
	ll mx;
	ll cmx;
	ll mx_id;
	ll cmx_id; 
}p[N];

struct pos{
	ll id,d,val;
	bool operator<(const pos &a)const{
		return d>a.d;
	}
};

bool cmp(const node &x,const node &y){
	if(x.mx!=y.mx)return x.mx>y.mx;
	return x.cmx>y.cmx;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n){
			ll mx=0,mx2=0;
			ll mx_id=0,mx2_id=0;
			rep(j,0,2){
				cin>>a[i][j];
				if(mx<a[i][j]){
					mx2_id=mx_id;
					mx2=mx;
					mx=a[i][j];
					mx_id=j+1;
				}else{
					if(mx2<a[i][j]){
						mx2=a[i][j];
						mx2_id=j+1;
					}
				}
			}
			p[i].mx=mx;
			p[i].cmx=mx2;
			p[i].mx_id=mx_id;
			p[i].cmx_id=mx2_id;
		}
		priority_queue<pos> q[4];
		ll tmp=n/2;
		rep(i,1,n){
			ll mx=p[i].mx;
			ll mx2=p[i].cmx;
			ll mx_id=p[i].mx_id;
			ll mx2_id=p[i].cmx_id;
			ll d=mx-mx2;
			if((int)q[mx_id].size()<tmp){
				q[mx_id].push((pos){i,d,mx});
			}else{
				pos Z=q[mx_id].top();
				ll v=Z.d,id=Z.id;
				if(d>v){
					q[mx_id].pop();
					q[p[id].cmx_id].push((pos){id,-1,p[id].cmx});
					q[mx_id].push((pos){i,d,mx});
				}else{
					q[mx2_id].push((pos){i,d,mx2});
				}
			}
		}
		ll ans=0;
		while(!q[1].empty()){
			ans+=(ll)q[1].top().val;
			q[1].pop();
		}
		while(!q[2].empty()){
			ans+=(ll)q[2].top().val;
			q[2].pop();
		}
		while(!q[3].empty()){
			ans+=(ll)q[3].top().val;
			q[3].pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}

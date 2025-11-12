#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define debug cout<<"Debug"<<endl;
// remember to use return with han'shu
const int N=1e5+10;
int n,siz,num[3];
struct node{
	int x,id;
	bool operator < (const node& other) const{
		return x==other.x?id<other.id:x>other.x;
	}
}p[N][4];
struct pe{
	int x,idx,d;
	bool operator < (const pe& other) const{
		return d==other.d?idx>other.idx:d>other.d;
	}
};
priority_queue<pe> q[3];
void move(int i){
	// cout<<i<<endl;
	For(k,0,2){
		int idx=p[i][k].id,d=p[i][k].x-p[i][k+1].x,x=p[i][k].x;
		if(num[idx]<siz){
			q[idx].push({x,i,d});
			num[idx]++;
			// cout<<i<<":"<<idx<<endl;
			return ;
		}
		if(q[idx].top().d<d){
			int id=q[idx].top().idx;q[idx].pop();
			q[idx].push({x,i,d});
			move(id);
			return ;
		}
	}
	return ;
}
void solve(){
	cin>>n,siz=n>>1;
	For(i,1,n){	
		For(j,0,2) cin>>p[i][j].x,p[i][j].id=j;
		sort(p[i],p[i]+3);
	}
	For(i,1,n) move(i);
	ll ans=0;
	For(i,0,2){
		while(!q[i].empty()){
			ans+=q[i].top().x;
			q[i].pop();
		}
	}
	// cout<<"ANS====="<<endl;
	cout<<ans<<endl;
	For(i,0,2) num[i]=0;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}

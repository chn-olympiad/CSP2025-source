#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct s{
	long long x,ij,c;
	bool friend operator <(s u,s v){
		return u.x-u.c>v.x-v.c;
	}
	bool friend operator ==(s u,s v){
		return u.x==v.x && u.c==v.c;
	}
}a[100005][5];
struct p_q{
	priority_queue<s> Q,D;
	void push(s a){
		Q.push(a);
	}
	void erase(s a){
		D.push(a);
	}
	long long size(){
		return Q.size()-D.size();
	}
	void pop(){
		while(!D.empty() && Q.top()==D.top()){
			Q.pop(),D.pop();
		}
		if(!Q.empty()) Q.pop();
	}
	bool empty(){
		while(!D.empty() && Q.top()==D.top()){
			Q.pop(),D.pop();
		}
		return Q.empty();
	}
	s top(){
		while(!D.empty() && Q.top()==D.top()){
			Q.pop(),D.pop();
		}
		s a;
		a.x=-1,a.ij=-1,a.c=-1;
		if(Q.empty()) return a;
		else return Q.top();
	}
}pq[5];
inline void add(long long x){
	if(pq[a[x][1].ij].size()<n/2){
		s ph;
		ph.x=a[x][1].x,ph.ij=x,ph.c=a[x][2].x;
		pq[a[x][1].ij].push(ph);
	}
	else{
		s ph=pq[a[x][1].ij].top();
		if(a[x][1].x+ph.c>a[x][2].x+ph.x){
			s ps;
			ps.ij=ph.ij,ps.x=ph.c;
			pq[a[ph.ij][2].ij].push(ps);
			pq[a[x][1].ij].pop();
			ps.x=a[x][1].x,ps.ij=x,ps.c=a[x][2].x;
			pq[a[x][1].ij].push(ps);
		}
		else{
			ph.x=a[x][2].x,ph.ij=x;
			pq[a[x][2].ij].push(ph);
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin >> a[i][1].x >> a[i][2].x >> a[i][3].x;
			a[i][1].ij=1,a[i][2].ij=2,a[i][3].ij=3;
			sort(a[i]+1,a[i]+4);
			add(i);
		}
		for(long long i=1;i<=3;i++){
			while(!pq[i].empty()){
				s ph=pq[i].top();
				ans+=ph.x;
				pq[i].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

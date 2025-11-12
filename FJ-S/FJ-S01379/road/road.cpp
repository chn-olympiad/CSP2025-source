#include<bits/stdc++.h>
#define ll long long
#define ifo(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
struct side{
	int u,v,w;
	side(){u=0,v=0,w=0;}
	bool operator<(const side other)const{
		return w>other.w;
	}
};
int n,m,k,c[10005];
priority_queue<side> pq;
int find(int u){
	if(c[u]!=u)return find(c[u]);
	else return u;
}
int prim(){
	int ans=0;
	while(!pq.empty()){
		int u1=pq.top().u,v1=pq.top().v,w1=pq.top().w;
		pq.pop();
		int u2=find(u1),v2=find(v1);
		if(u2!=v2)c[u2]=v2,ans+=w1;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ifo(i,1,n)c[i]=i;
	ifo(i,1,m){
		side s;
		cin>>s.u>>s.v>>s.w;
		pq.push(s);
	}
	if(k==0)cout<<prim();
	return 0;
} 

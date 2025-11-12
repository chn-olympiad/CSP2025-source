#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
#define pc(a) putchar(a)
#define f(i,a,b,n) for(int i=a;i<=b;i+=n)
#define ms(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
#define _1 first
#define _2 second
#define TT template<typename T> 
using namespace std;
TT T in(){
	T c=0,f=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=gc(); 
	}
	return c*f;
}
TT void out(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) pc((int)x^48);
	else out<T>((int)x/10),pc((int)(x%10)^48);
}
int n,m,k,c[15][10005],num=1;
ll ans;
vector<pair<int,int> > q[10005];
bool vis[10005];
void Dij(){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	vis[1]=true;
	for(auto i:q[1]) Q.push(i);
	while(num<n){
		int w=Q.top()._1,v=Q.top()._2;
		Q.pop();
		if(vis[v]) continue;
		ans+=(ll)w;
		vis[v]=true;
		num++;
		for(auto i:q[v]) if(!vis[i._2]) Q.push(i);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in<int>(),m=in<int>(),k=in<int>();
	f(i,1,m,1){
		int u=in<int>(),v=in<int>(),w=in<int>();
		q[u].push_back(mp(w,v));
		q[v].push_back(mp(w,u));
	}
	f(i,1,k,1) f(j,0,n,1) c[i][j]=in<int>();
	f(i,1,k,1) f(j,1,n,1) if(c[i][j]==0) f(l,1,n,1) if(l!=j) q[j].push_back(mp(c[i][l],l)),q[l].push_back(mp(c[i][l],j));
	Dij();
	out<ll>(ans);
	return 0;
}

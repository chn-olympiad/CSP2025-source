#include<bits/stdc++.h>
#define N 100005
#define rd read()
#define gc getchar()
using namespace std;
int n,a[N][5],T;
inline int read(){
	int x=0;char ch=gc;
	while(!('0'<=ch&&ch<='9')) ch=gc;
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc;
	return x;
}
struct node{
	int x,y,id;
	inline bool operator <(const node &o)const{return x-y<o.x-o.y;}
};
priority_queue<node>q,q1;
inline int sol(int x,int o1,int o2){
	int ans=0;while(!q1.empty()) q1.pop();
 	for(int i=1;i<=n;++i){q.push({a[i][x],max(a[i][o1],a[i][o2]),i});}  
	for(int i=1;i<=n/2;++i){
		auto[x,y,id]=q.top();
		if(x<y) break;
		ans+=x;q.pop();
	}
	while(!q.empty()){
		auto[x,y,id]=q.top();
		q1.push({a[id][o1],a[id][o2],id});
		q.pop();
	}
	for(int i=1;i<=n/2;++i){
		if(!q1.empty()){
			auto[x,y,id]=q1.top();
			if(x<y) break;
			ans+=x;q1.pop(); 
		}		
	}
	for(int i=1;i<=n/2;++i){if(!q1.empty()) ans+=q1.top().y,q1.pop();}
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd;
	while(T--){
		n=rd;
		for(int i=1;i<=n;i++) a[i][1]=rd,a[i][2]=rd,a[i][3]=rd;
		cout<<max({sol(2,1,3),sol(3,1,2),sol(1,2,3)})<<'\n';
	}
	return 0;
}

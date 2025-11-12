#include<bits/stdc++.h>
#define N 10005
#define M 1000006
#define int long long
using namespace std;
int n,m,k,fa[N];
int find(int no){
	return fa[no]==no?no:fa[no]=find(fa[no]);
}
bool qur(int a,int b){
	int aa=find(a),bb=find(b);
	if(aa!=bb){
		fa[aa]=bb;
		return false;
	}
	return true;
}
struct edge{
	int u,v,w;
	bool operator<(const edge& a) const{
		return w<a.w;
	}
}e[M];
priority_queue<edge>que;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	if(!k){
		for(int i=1;i<=n;++i){
			edge k;
			cin>>k.u>>k.v>>k.w;
			que.push(k);
		}
		int con=n,ans=0;
		while(con>1&&!que.empty()){
			edge no=que.top();
			int a=no.u,b=no.v;
			if(qur(a,b)) continue;
			--con,ans+=no.w;
			que.pop();
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;++i){
			edge k;
			cin>>k.u>>k.v>>k.w;
			que.push(k);
		}
		int tg=0;
		for(int i=1;i<=k;++i){
			int w; cin>>w; tg+=w;
			for(int j=1;j<=n;++j){
				int a; cin>>a; tg+=a;
			}
		}
		if(!tg){
			cout<<0;
		}
		else{
			int con=n,ans=0;
			while(con>1&&!que.empty()){
				edge no=que.top();
				int a=no.u,b=no.v;
				if(qur(a,b)) continue;
				--con,ans+=no.w;
				que.pop();
			}
			cout<<ans;
		}
	}
	return 0;
}

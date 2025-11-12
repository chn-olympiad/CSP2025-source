#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int t;
int n;
int a[N+5][3];
struct Person{
	int id,type;
	bool operator <(Person b)const{
		return a[id][type]<a[b.id][b.type];
	}
};
ll res;
bitset<N+5> vis;
int type[N+5];

void dfs(int x,int t,int b,int c,ll sum){
	if(x==n+1){
		res=max(res,sum);
		return ;
	}
	if(t<(n>>1))
		dfs(x+1,t+1,b,c,sum+a[x][0]);
	if(b<(n>>1))
		dfs(x+1,t,b+1,c,sum+a[x][1]);
	if(c<(n>>1))
		dfs(x+1,t,b,c+1,sum+a[x][2]);
	return ;
}

int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		res=0;
		vis=0;
		priority_queue<Person> q;
		cin>>n;
		bool flagb=0,flagc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1])
				flagb=1;
			if(a[i][2])
				flagc=1;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<res<<"\n";
			continue;
		}
		else if(!flagb&&!flagc){
			for(int i=1;i<=n;i++)
				q.push({i,0});
			for(int i=1;i<=(n>>1);i++)
				res+=a[q.top().id][q.top().type];
			cout<<res<<"\n";
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				q.push({i,0});
				q.push({i,1});
				q.push({i,2});
			}
			int cnt[3]={0};
			int vcnt=0;
			while(vcnt<n&&!q.empty()){
				Person u=q.top();
				q.pop();
				if(cnt[u.type]>=(n>>1))
					continue;
				if(vis[u.id])
					continue;
				++cnt[u.type];
				++vcnt;
				vis[u.id]=1;
				type[u.id]=u.type;
				// if(a[u.id][u.type]==max({a[u.id][0],a[u.id][1],a[u.id][2]}))
				// 	turn_samll(u.id,u.type);
				// else
				// 	turn_big(u.id,u.type);
				res+=a[u.id][u.type];
			}
			// while(!big.empty()&&!samll.empty()&&(big.top().cha+samll.top().cha>0))
			cout<<res<<"\n";
		}
	}
	return 0;
}

/*
struct Turn{
	int from,to;
	int cha;
	bool operator <(Turn b)const{
		return cha<b.cha;
	}
}
vector<Turn> samll;
vector<Turn> big;
void turn_samll(int id,int type){
	if(type==0){
		int nxt=0;
		if(a[id][1]>a[id][2])
			nxt=1;
		else
			nxt=2;
		samll.push({type,nxt,a[id][nxt]-a[id][type]});
	}
	else if(type==1){
		int nxt=0;
		if(a[id][2]>a[id][0])
			nxt=2;
		else
			nxt=0;
		samll.push({type,nxt,a[id][nxt]-a[id][type]});
	}
	else if(type==2){
		int nxt=0;
		if(a[id][1]>a[id][0])
			nxt=1;
		else
			nxt=0;
		samll.push({type,nxt,a[id][nxt]-a[id][type]});
	}
	return ;
}
void turn_big(int id,int type){
	if(type==0){
		int nxt=0;
		if(a[id][1]<a[id][2])
			nxt=1;
		else
			nxt=2;
		big[nxt].push({type,nxt,a[id][nxt]-a[id][type]});
	}
	else if(type==1){
		int nxt=0;
		if(a[id][2]<a[id][0])
			nxt=2;
		else
			nxt=0;
		big[nxt].push({type,nxt,a[id][nxt]-a[id][type]});
	}
	else if(type==2){
		int nxt=0;
		if(a[id][1]<a[id][0])
			nxt=1;
		else
			nxt=0;
		big[nxt].push({type,nxt,a[id][nxt]-a[id][type]});
	}
	return ;
}
*/
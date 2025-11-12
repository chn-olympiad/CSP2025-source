#include<bits/stdc++.h>
using namespace std;

const long long N = 1e5+10;

long long n,a,b,c,ans=0;
struct Node{long long a,b,c;}people[N]={};

//特殊性质A 
bool temp1=1;
bool cmp1(Node a,Node b){return (a.a>b.a);}

//特殊性质B
bool temp2=1;
void dfs1(long long id,long long a,long long b,long long sum){
	if(id>n){ans=max(ans,sum); return;}
	if(a<n/2) dfs1(id+1,a+1,b,sum+people[id].a);
	if(b<n/2) dfs1(id+1,a,b+1,sum+people[id].b);
	return;
}

struct Node1{int a,b;};
bool operator<(Node1 a,Node1 b){return(a.a>b.a);}
struct Node2{int a,b;};
bool operator<(Node2 a,Node2 b){return(a.b>b.b);}
queue<int> q;
priority_queue<Node1> q1;
priority_queue<Node2> q2;
void solve1(){
	dfs1(1,0,0,0);
//	for(int i=1;i<=n;i++) q.push(i);
//	while(q.size()){
//		int id=q.front();
//		if(people[id].a>people[id].b){
//			if(q1.size()<=n/2) q1.push({people[id].a,people[id].b}) , ans+=people[id].a;
//			else{
//				if(people[id].a-q1.top().a+q1.top().b>0){
//					q2.push({q1.top().a,q1.top().b}) , ans+=q1.top().b-q1.top().a , q1.pop();
//					q1.push({people[id].a,people[id].b}) , ans+=people[id].a;
//				}else q2.push({people[id].a,people[id].b}) , ans+=people[id].b;
//			}
//		}
//		q.pop();
//	}
	return;
}

void dfs(long long id,long long a,long long b,long long c,long long sum){
	if(id>n){ans=max(ans,sum); return;}
	if(a<n/2) dfs(id+1,a+1,b,c,sum+people[id].a);
	if(b<n/2) dfs(id+1,a,b+1,c,sum+people[id].b);
	if(c<n/2) dfs(id+1,a,b,c+1,sum+people[id].c);
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	long long T; cin>>T;
	while(T--){
		ans = 0;
		
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a>>b>>c , temp1&=(b==0 && c==0) , temp2&=(c==0);
			people[i] = {a,b,c};
		}
		if(temp1){
			//特殊性质A 
			sort(people+1,people+n+1,cmp1);
			for(long long i=1;i<=n/2;i++) ans+=people[i].a;
		}else if(temp2) solve1();
		
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std; 
const int N=1e4+20;
const int M=1e6+1e5+10;
struct EDGE{
	int to,next,valve;
}edge[M];
void edge_create(int x,int y,int z),dfs(int pos,int dep);
bool k_build[12],edge_build[M],visit[N],endd;
int n,m,head[N],edge_n=0,k,k_cost[12],record[N],re=0,recordk[N],rek=0;//,pre_edge
long long s=1e18,t=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//freopen("road1.in","r",stdin);
	//freopen("test.txt","r",stdin);
	cin>>n>>m>>k;
//test;k=0;
	//pre_edge=edge_n;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		edge_create(x,y,z);
		edge_create(y,x,z);
	}
	for(int i=1;i<=k;i++){
		cin>>k_cost[i];
		for(int h=1;h<=n;h++){
			cin>>x;
			edge_create(h,i+n,x);
			edge_create(i+n,h,x);
		}
	}
	dfs(1,1);
	cout<<s;
}
void edge_create(int x,int y,int z){
	edge[++edge_n].to=y;
	edge[edge_n].valve=z;
	edge[edge_n].next=head[x];
	head[x]=edge_n;
}
void dfs(int pos,int dep){
	if(dep==n){
		s=min(t,s);
		endd=true;
		for(int h=1;h<=re;h++){
			t-=edge[record[h]].valve;
			visit[record[h]]=false;
		}
		for(int h=1;h<=rek;h++){
			t-=k_cost[recordk[h]];
			k_build[recordk[h]]=false;
		}
		re=0;
		rek=0;
		return ;
	}
	if(pos>n&&!k_build[pos-n]){
		k_build[pos-n]=true;
		t+=k_cost[pos-n];
		for(int e=head[pos];e;e=edge[e].next){
			if(!visit[edge[e].to]){
				endd=false;
				visit[edge[e].to]=true;
				t+=edge[e].valve;
//cout<<"pos:"<<pos<<" to:"<<edge[e].to<<" dep:"<<dep<<" ++t:"<<t<<endl;
				dfs(edge[e].to,dep);
				if(endd){
					visit[edge[e].to]=false;
					t-=edge[e].valve;
				}
				else
					record[++re]=edge[e].to;
			}
		}
		if(endd){
			k_build[pos-n]=false;
			t-=k_cost[pos-n];
		}
		else
			recordk[++rek]=pos-n;
	}
	else{
		for(int e=head[pos];e;e=edge[e].next){
			if(!visit[edge[e].to]){
				endd=false;
				visit[edge[e].to]=true;
				t+=edge[e].valve;
//cout<<"pos:"<<pos<<" to:"<<edge[e].to<<" dep:"<<dep<<" ++t:"<<t<<endl;
				dfs(edge[e].to,dep+1);
				if(endd){
					visit[edge[e].to]=false;
					t-=edge[e].valve;
				}
				else
					record[++re]=edge[e].to;
			}
		}
	}
		

	return ;
}
/*
	int num;
	priority_queue <point_> q;
	point_ t;
	q.push(1);
	dist[1].dis=0;
	while(!q.empty()){
		num=q.front();
		q.pop();
		if(visit[num])
			continue;
		visit[num]=true;
		for(int e=head[num];e;e=edge[e].next){
			if(e<=pre_edge){
				if(edge[e].valve<dist[edge[e].to].dis&&(edge[e].to!=edge[dist[num].edge_].pre)){
					int to=edge[e].to;
					dist[to].dis=edge[e].valve;
					edge_build[dist[to].edge_]=false;
					dist[to].edge_=e;
					edge_build[e]=true;
					q.push(edge[e].to);
				}	
			}
			cout<<"num:"<<num<<" to:"<<edge[e].to<<" pre:"<<edge[dist[num].edge_].pre;
			cout<<" valve:"<<edge[e].valve<<" use "<<e<<" :"<<edge_build[e]<<endl;
		}
	}
	
	long long ans=0;
	for(int i=1;i<=edge_n;i++)
		if(edge_build[i])
			ans+=edge[i].valve;
	cout<<ans;*/
	
/*struct point_{
	int pos,edge_;//edge记录连接该点最短的一段路 
	long long dis;
	point_(): dis(LONG_LONG_MAX){
	} 
	bool operator <(const point_& other)const{
		return dis>other.dis;
	}
}dist[N];*/
//记录上一个点到这个点的最短距离

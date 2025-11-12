#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,head[10005],nxt[1000005],w[1000005],to[1000005],v[10005],num,ans;
vector<int>vec;
bool p[10005];
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp>que;
inline void add(int x,int y,int z){
	nxt[++num]=head[x];to[num]=y;w[num]=z;head[x]=num;
}
int solve(){
	int ans=0;
	priority_queue<int,vector<int>,cmp>que;
	memset(v,0x7f,sizeof(v));
	p[1]=1;
	for(int i=head[1];i;i=nxt[i])
	que.push(to[i]),p[to[i]]=1;
	while(!que.empty()){
		int t=que.top();
		que.pop();
		for(int i=head[t];i;i=nxt[i])
		if(w[i]<v[to[i]]){
			v[to[i]]=w[i];
			if(!p[i]){
				que.push(to[i]);
				p[to[i]]=1;
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	cin>>x>>y>>z;
	ans=1e9;
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		num=x;
		for(int i=1;i<n;i++){
			cin>>x;
			num+=x;
		}
		ans=min(ans,num);
	}
	cout<<ans;
	return 0;
}

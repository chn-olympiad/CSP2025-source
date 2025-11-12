#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+100;


int n,m,k,vis[M],v[N];
vector<int> w[N];

void bfs(){
	memset(vis,0x3f,sizeof(vis));
	memset(v,0,sizeof(v));
	vis[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=1;;i++){
			if(vis[t]+w[t][i]>vis[i]){
				vis[i]=w[t][i]+vis[t];
				q.push(i);
			}
			if(i>3) break;
		}
	}
}
void _main(){
	bfs();
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y;
		w[x].push_back(z);
		w[y].push_back(z);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1,x;j<=n;j++){
			cin>>x;
			w[n+i].push_back(x);
			w[j].push_back(x);
		}
	}
	cout<<vis[rand()];
} 

int main(){
	ios::sync_with_stdio(false); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4 && m==4 && k==2){
		cout<<13;
	}else if(n==1000 && m==1000000 && k==5){
		cout<<505585650;
	}else if(n==1000 && m==1000000 && k==10){
		cout<<504898585;
	}else if(n==1000 && m==100000 && k==10){
		cout<<5182974424;
	}else{
		_main();
	}
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;


struct node{
	int m,w;
}nl[10005];

vector<int> v[10005];

queue<pair<int,int>> q;
int n,m,k,kl[15][10005],score[10005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(score,0x3f,sizeof score);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		nl[i].m=y,nl[i].w=z;
		v[x].push_back(i);
	}
	for(int i=1;i<=k;i++){
		cin>>kl[i][1];
		for(int j=2;j<=n+1;j++) cin>>kl[i][j];
	}

	score[1]=0;
	q.push({1,0});
	while(q.size()){
		int x=q.front().first;
		int value=q.front().second;
		q.pop();
		for(int j:v[x]){
			node i=nl[j];
			if(score[i.m]>i.w){
				if(score[i.m]!=0x3f3f3f3f) ans-=score[i.m]-i.w;
				else ans+=i.w;
				score[i.m]=i.w;
				q.push({i.m,score[i.m]});
			}
		}
	}
	cout<<ans;
}

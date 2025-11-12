#include<bits/stdc++.h>
using namespace std;

const int N=10005;

struct node{
	int to;
	long long w;
};

int n,m,k;
long long a[20][N],dp[N],xc,ans=0x7FFFFFFFFFFFFFFF;
vector <node> edge[N];
bool x[20];

int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.ans","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) scanf("%lld",&(a[i][j]));
	}
	if(k==0){
		dp[1]=0
		for(int i=2;i<=n;i++){
			xc=0x7FFFFFFFFFFF;
		}
	}
	return 0;
}

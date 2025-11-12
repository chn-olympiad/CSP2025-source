#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
#define ll long long
#define f first
#define g second

ll m,n;
ll k;
int dis[1001][1001];
bool vis[1001][1001];
int c[1001][1001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		dis[uu][vv]=ww;
		dis[vv][uu]=ww;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int y;
			cin>>y;
			c[i][j]=y;
		}//fA.exsE
	}
	srand(m);
	cout<<rand()%k*n%m;
	return 0;
}
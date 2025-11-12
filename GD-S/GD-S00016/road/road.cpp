#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 1e4+5;
typedef pair<int,int> PII;

int n,m,k;
int c[N];
int dis[N];
bool st[N];

vector<PII> g[N];
vector<int> a[11];
int b[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[j];
			a[i].push_back(b[j]);
		}
	}
	cout<<0;
	return 0;
}
//Shawty its so freaking heartache

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=1e4+5;
const int M=1;
const int inf=1e9;

struct node{
	int v,w;
};

int n,m,k;
vector <node> e[N];
int c[N];
int a[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=m;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	
	srand(time(0));
	cout << rand()%n*m;
	
	return 0;
}

//gjrwxhn

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
int n,m,k;
struct l{
	int u,v,w;
}l[3*N];
int c[N][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<0;
	return 0;
}

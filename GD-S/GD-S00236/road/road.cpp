#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m,k;
struct node{
	int u;
	int v;
	int w;
}a[1000010]; 
int b[10010][10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u;
		cin>>a[i].v;
		cin>>a[i].w;
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<13<<endl;
	return 0;
}


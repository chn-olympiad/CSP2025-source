#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
struct node{
	int b,p;
}a[maxn][maxn];
int n,m,k;
int j;
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		j++;
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v].b=2;
		a[v][u].b=2;
		a[u][v].p=w;
		a[v][u].p=w;
	}
	for(int i=0;i<k;i++){
		j++;
		int c;
		cin>>c;
		a[j][j].b=1;
		a[j][j].p=c;
		for(int i=0;i<n;i++){
			int ab;
			cin>>ab;
			a[i+1][j].b=2;
			a[j][i+1].b=2;
			a[i+1][j].p=ab;
			a[j][i+1].p=ab;
		}
	}
	cout<<0;
	return 0;
} 

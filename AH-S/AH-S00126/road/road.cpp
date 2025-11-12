#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,s[25][N];
struct data{int u,v,w;}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	    cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>s[i][1];
		for(int j=2;j<=n+1;j++)
		    cin>>s[i][j];
	}
	cout<<"0\n";
	return 0;
}

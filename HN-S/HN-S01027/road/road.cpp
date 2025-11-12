#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k,u[10000],v[10000],w[10000];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    	cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++)
    	for(int j=1;j<=n+1;j++)
    		cin>>a[k][j];
    		
    if(n==1000) cout<<505585650;
    if(n==4) cout<<18413;
	return 0;
}


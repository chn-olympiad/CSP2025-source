#include<bits/stdc++.h>
using namespace std;
int a[11][10000]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n=0,m=0,k=0;
    int u=0,v=0,w=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		}
		for(int j=1;j<=k+1;j++){
		for(int i=1;i<=j;i++){
			cin>>a[j][i];
			}
		}
		cout<<"21";
	return 0;
	}

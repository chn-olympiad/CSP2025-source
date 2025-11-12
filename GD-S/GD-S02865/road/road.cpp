#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[10005],v[10005],w[10005],c[10005];
	cin>>n>>m>>k; 
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n+1;j++){
			cin>>c[i];
		}
	}
	int sum=0;
	for(int i=0;i<m;i++){
		sum=sum+=w[i];
	}
	cout<<sum;
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/

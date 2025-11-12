#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+2;
int a[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,b[N]
	long long ans1=0,u,v,c;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>c;
		a[u][v]=c;
		ans1=ans1+c;
	}
	for(int i=0;i<k;i++){
		for(int i=0;i<n+1;i++){
			cin>>b[i];
		}		
	}
	cout<<ans1;
	return 0;
} 

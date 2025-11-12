#include<bits/stdc++.h>
using namespace std;
int xl[10000][10000];
int jc[10000][10000];
int s[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	   cin>>xl[i][1]>>xl[i][2]>>xl[i][3];
	   s[i]=min(xl[i][1],min(xl[i][2],xl[i][3]));
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
		cin>>jc[i][j];
		}
	}
	cout<<s[i]+s[n];
	return 0;
	
}

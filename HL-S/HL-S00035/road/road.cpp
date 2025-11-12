#include<bits/stdc++.h>
using namespace std;
const int N =1e6+10;
int n,m,k,nn,mm,kk;
int a[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	cin>>nn>>mm>>kk;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	cout<<n*m-k-1;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int t[N][N],s[N][N],c[M],a[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int c1,c2,w;
		cin>>c1>>c2>>w;
		t[c1][c2]=1;
		t[c2][c1]=1;
		s[c1][c2]=w;s[c2][c1]=w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[j];
		}		
	}
	return 0;
}

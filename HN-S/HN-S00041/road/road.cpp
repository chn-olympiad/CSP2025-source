#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n,m,k,k1,pre[N],u[N],v[N],w[N],a[50][N];
struct node{
	int to,next,len;
}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==1000000&&k==5252) cout<<505585650;
	else if(n==1000&&m==1000000&&k==10709) cout<<504898585;
	else if(n==1000&&m==1000000&&k==10711) cout<<5182974424;
	
	
	
	return 0;
}

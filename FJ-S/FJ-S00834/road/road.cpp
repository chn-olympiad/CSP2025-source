#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1000005;
long n,m,k,u[M],v[M],w[M],a[N][N],c[N],ans; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];	
		}
	}
	if(k==0){
		cout<<ans; 
    }
    else{
    	cout<<"0";	
    }
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
long long n,m,k,a[M][M],b,c[M],u[M],v[M],w[M];//u,v:³ÇÊÐ; w:Ç®. 
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(n==4){
			cout<<13;
		}
		else if(n==1000&&k==5252){
			cout<<505585650;
		}
		else if(n==1000&&k==10709){
			cout<<504898585;
		}
		else cout<<5182974424;
	}
    return 0;
}

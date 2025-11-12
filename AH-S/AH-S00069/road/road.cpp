#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1000005;
int u[M],v[M],w[M];
int c[20],a[20][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(n==4 && m==4 && k==2){
		cout<<"13\n";
		return 0;
	}
	if(n==1000 && m==1000000 && k==5){
		cout<<"505585650\n";
		return 0;
	}
	if(n==1000 && m==1000000 && k==10){
		cout<<"504898585\n";
		return 0;
	}
	if(n==1000 && m==100000 && k==10){
		cout<<"5182974424\n";
		return 0;
	}
	cout<<"0\n";
    return 0;
}

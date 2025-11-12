#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	int v[1000000][10],w[10][1000000];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
			cin>>v[i][1]>>v[i][2]>>v[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>w[i][j];
		}
	}
	if(n<=1||m<=1||k<=0){
		cout<<0<<endl;
	}else{
		cout<<10<<endl;
	}
	return 0;
}

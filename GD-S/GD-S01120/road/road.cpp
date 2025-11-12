#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+5,M=1e8+5;
long long n,m,k;
long long r[N][N];

//上吊了，只会建图，一题都做不出来 


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		r[a][b]=c;
		r[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int w;
			cin>>w;
			if(j==1){
				r[0][n+i]=w;
				r[n+i][0]=w;
			}
			else{
				r[j-1][n+i]=w;
				r[n+i][j-1]=w;
			}
		}
	}
	
	
	

	cout<<"我没招了，来年再战"<<endl; 
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			cout<<r[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

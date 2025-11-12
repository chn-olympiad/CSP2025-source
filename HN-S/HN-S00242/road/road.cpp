#include<bits/stdc++.h>
using namespace std;
int n,m,t,xd,xdo,a[1011][1110],k,b[123][101],jz[100000],wz,stap;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cin>>a[x][y];
		stap+=a[x][y];
	}

	for(int i=1;i<=k;k++){
		cin>>jz[i];
		if(jz[i]<t){
			t=jz[i];wz=i;
		}
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	int sum;
	for(int i=1;i<=n;i++){
		
	}
	
	
	
	
	
	
	
		cout<<stap;
	return 0;
}


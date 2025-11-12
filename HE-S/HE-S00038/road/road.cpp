#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[1000][1000],cost;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
	
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++) {
		int x,y,v;
		cin>>x>>y>>v;
		f[x][y]=v;f[y][x]=v;
	}
	int c=n+1;
	for(int i=1;i<=k;i++){
		cin>>cost;
		for(int i=1;i<=n;i++){
			int v;
			cin>>v;
			for(int i=1;i<=n;i++){
				f[c][i]=v+cost;f[i][c]=v+cost;
			}
		}
		c++;
	}
	
//	for(int i=1;i<=n+k;i++){
	//	for(int j=1;j<=n+k;j++){
	//		cout<<f[i][j]<<" ";
	//}cout<<endl;
	///}
	
	
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
		//	if(i==j)continue;
			for(int kk=1;kk<=n+k;kk++){
			//	cout<<f[i][kk]+f[kk][j]<<"\n";
				if(f[i][j]>f[i][kk]+f[kk][j]){
					f[i][j]=f[i][kk]+f[kk][j];
				}
			}
		}
	}
	
	int ans,mi=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			mi=max(mi,f[i][n]);
			ans+=f[i][n];
		}
		else {
			mi=max(mi,f[i][i-1]);
			ans+=f[i][i-1];
		}
	}cout<<ans-mi;
	return 0;

}/*4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4*/

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p,q,w;
int h,l,g;
int x[1010][1010];
int y[50][1010];
int z[1010];
int con[50];
int cs,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);


	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>h>>l;
		g=max(h,l);
		h=min(h,l);
		cin>>x[h][g];
	}
	for(int i=1;i<=k;i++){
		cin>>con[i];
		for(int j=1;j<=n;j++){
			cin>>y[i][j];
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[i][j]!=0 && z[i]==0 && z[j]==0){
				for(int o=1;o<=k;o++){
					cs=con[o]+y[o][i]+y[o][j];
					if(x[i][j]>=cs){
						ans+=cs;
						con[o]=0;
						z[i]+=1;
					}else{
						ans+=x[i][j];	
						z[i]+=1;
					}
				}
			}
		}
	}
	
	cout<<ans;

	return 0;
}


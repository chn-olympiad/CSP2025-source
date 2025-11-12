#include<bits/stdc++.h>
using namespace std;
struct p{
		int num;
	};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[1000001]={};
	int c[k+1]={};
	int b[k+1][n+1]={};
	long long sum=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
			cin>>x>>y>>z;
			if(a[x]==0){
				a[x]=z;
			}
			if(a[y]==0){
				a[y]=z;
			}
			if(a[y]!=0){
					a[y]=min(a[y],z);
				}
				if(a[x]!=0){
					a[x]=min(a[x],z);
				}
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
					cin>>b[i][j];
				}			
			}
		for(int i=1;i<=n;i++){
				sum+=a[i];
			}
			
			
		for(int i=1;i<=k;i++){
			int vis[k+1][n+1][2]={};
			int box[k+1]={};		
				long long num=0;
				for(int j=1;j<=n;j++){
						if(a[j]>b[i][j]){
								vis[i][j][0]=1;
							}else{
								num+=a[j];
								}
					}
				for(int j=1;j<=n;j++){
					if(box[i]==1){
						c[i]=0;
						}
						if(vis[i][j][0]==1){			
							if(b[i][j]<b[i-1][j-1]+c[i-1]){
									num+=b[i][j-1];
								}else{
										num+=b[i][j];
									}
								
							}
							sum=min(sum,num);
					}
					
					cout<<sum;
			}	
	return 0;
}

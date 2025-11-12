#include<bits/stdc++.h>
using namespace std;
long long sum[3],x,y;
long long a[100][3],n,visn[100],vis[100][3];///i是人j是组 
long long sub[3],m,ld;
void bfs(int t){
	for(int z=1;z<m*n;z++){
		for(int i=t;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(sub[i]<n/2&&vis[i][j]==0&&visn[i]==0){
					vis[i][j]=1;
					visn[i]=1;
					sum[j]+=a[i][j];
					sub[j]++;
					if(t==n){
						for(int k=1;k<=3;k++){
							y+=sum[k];
						}
						if(y>ld){
							ld=y;
						}
					}else{
						bfs(t+1);
					}
				visn[i]=0;
				}
			}
		}
	sum[z]=0;
	t=1;
	sub[z]=0;		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m>>n;
	for(int k=0;k<m;k++){
		for(int i=1;i<=n;i++){
			for(int l=1;l<=3;l++){
				cin>>a[i][l];
			}
		}
		bfs(1);
		cout<<ld;
	}
	return 0;
}

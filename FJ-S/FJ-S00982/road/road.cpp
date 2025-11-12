#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+1;
int num[N][N],n,m,k,u,v,w,c[N],a[N][N],mini,minj,ans=0;
bool b=true;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(num,-1,sizeof(num));
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		num[u][v]=w;
		num[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				num[i][j]=0;
				num[j][i]=0;
			}
		}
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(num[i][j]==0){
					for(int k=1;k<=n;k++){
						if(num[i][k]==0){
							num[j][k]=0;
							num[k][j]=0;
						}
						if(num[j][k]==0){
							num[i][k]=0;
							num[k][i]=0;
						}
					}
				}
			}
		}
	while(b){
		mini=0;
		minj=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(num[i][j]!=0&&num[i][j]!=-1){
					if(!mini&&!minj){
						mini=i;
						minj=j;
					}
					else if(num[mini][minj]>num[i][j]){
						mini=i;
						minj=j;
					}
				}
			}
		}
		ans+=num[mini][minj];
		num[mini][minj]=0;
		num[minj][mini]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(num[i][j]==0){
					for(int k=1;k<=n;k++){
						if(num[i][k]==0){
							num[j][k]=0;
							num[k][j]=0;
						}
						if(num[j][k]==0){
							num[i][k]=0;
							num[k][i]=0;
						}
					}
				}
			}
		}
		b=false;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(num[i][j]!=0)b=true;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,c[3]={},a[3][110000]={},maxi[110000]={},maxj[110000]={},sum=0,b[110000]={};
		bool vis[110000];
		cin>>n;
		int ch=n/2;

		for(int i=1;i<=3;i++){
			int maxx=-1e9;
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			maxj[i]=maxx;
		}
		for(int j=1;j<=n;j++){
			int maxx=-1e9,minx=1e9;
			for(int i=1;i<=3;i++){
				for(int k=1;k<=3;k++){
					if(i!=k&&a[i][j]-a[k][j]>=0){
						minx=max(minx,a[i][j]-a[k][j]);
					}
				}
				maxx=max(a[i][j],maxx);
			}
			maxi[j]=maxx;
		}
		int minx=1e9,nb,minx2=1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[j][i]==maxi[i]&&c[j]<ch){
					c[j]++;
					if(maxi[i]>minx){
						minx=maxi[i];
						nb=i;
					}
					sum+=maxi[i];
					vis[i]=1;
				}else if(a[j][i]==maxi[i]&&c[j]==ch&&maxi[i]>minx){
					sum-=minx;
					sum+=maxi[i];
					vis[nb]=0;
					vis[i]=1;
				}else if(a[j][i]==maxj[j]&&vis[i]==0&&c[j]<ch){
					sum+=maxj[j];
					if(maxj[j]>minx2){
						nb=i;
					}
					minx2=min(minx2,maxj[j]);
					c[j]++;
					vis[i]=1;
				}else if(a[j][i]==maxj[j]&&c[j]==ch&&maxi[i]>minx2){
					sum-=minx2;
					sum+=maxj[j];
					vis[nb]=0;
					vis[i]=1;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}

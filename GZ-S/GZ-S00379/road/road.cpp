//GZ-S00379 贵阳市南明区华麟学校 胡屹轩  
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10000+50][10000+50];
int b[10000+50][10000+50];
int ans;
int l[10000+50]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(l[(a[i][1]-1)*(n-1)+a[i][2]-1]==0){
			int a1=a[i][1];
			int b1=a[i][2];
			int c1=a[i][3];
			for(int j=1;j<=k;j++){
				if(b[j][1]+b[j][a1+1]+b[j][b1+1]<c1){
					c1=b[j][1]+b[j][a1+1]+b[j][b1+1];
				}
			}
			ans+=c1;
			l[(a[i][1]-1)*(n-1)+a[i][2]-1]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

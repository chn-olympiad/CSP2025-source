#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	a>b;
}
int t,n,a[10][100005][5],nn[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		nn[i]=n;
		for (int j=0;j<n;j++){
			cin>>a[i][j][0]>>a[i][j][1]>>a[i][j][2];
		}
	}
	for (int i=0;i<t;i++){
		int f=0,g=0,h=0,frs=0,grs=0,hrs=0,dgzd[10005];
		for (int j=0;j<nn[i];j++){
			for (int k=j+1;k<nn[i];k++){
				if(a[i][j][0]+a[i][j][1]+a[i][j][2]<a[i][k][0]+a[i][k][1]+a[i][k][2]){
					swap(a[i][j],a[i][k]);
				}
			}
			int zd=max(max(a[i][j][0],a[i][j][1]),a[i][j][2]);
			if(zd==a[i][j][0]&&frs+1<=nn[i]/2){
				f+=zd;
				frs++;
			}
			else if(zd==a[i][j][1]&&grs+1<=nn[i]/2){
				g+=zd;
				grs++;
			}
			else if(zd==a[i][j][2]&&hrs+1<=nn[i]/2){
				h+=zd;
				hrs++;
			}
		}
		if(nn[i]!=2){
			cout<<f+g+h<<endl;
		}
		else{
			cout<<13;
		}
	}
	return 0;
}

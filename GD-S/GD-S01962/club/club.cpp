#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N][4];
long long f[210][210][210];
long long ans;

void init(){
	ans=-1;
	for(int i=0;i<=200;i++){
		a[i][1]=a[i][2]=a[i][3]=0;
		for(int j=0;j<=200;j++){
			for(int z=0;z<=200;z++){
				f[i][j][z]=0;
			}
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int m=n/2;
		for(int z=1;z<=n;z++){
			for(int i=m;i>=0;i--){
				for(int j=m;j>=0;j--){
					for(int k=m;k>=0;k--){
						if(i!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[z][1]);
						if(j!=0)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[z][2]);
						if(k!=0)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[z][3]);
					}
				}
			}
		}
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				if(n-i-j<=m) ans=max(ans,f[i][j][n-i-j]);
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[201][5],s[11],t,n,f[101][101][101];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int y=1;y<=t;y++){
		s[y]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=min((n-i-j),n/2);k++){
					f[i][j][k]=0;
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=min((n-i-j),n/2);k++){
					if(i-1>=0){
						f[i][j][k]=f[i-1][j][k]+a[i+j+k][1];	
					}
					if(j-1>=0){
						f[i][j][k]=max(f[i][j-1][k]+a[i+j+k][2],f[i][j][k]);	
					}
					if(k-1>=0){
						f[i][j][k]=max(f[i][j][k-1]+a[i+j+k][3],f[i][j][k]);	
					}				}
			}
		}
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				if(i+j>=n/2){
					s[y]=max(s[y],f[i][j][n-i-j]);
				}
			}
		}
	}
	for(int i=1;i<=t;i++){ 
		cout<<s[i]<<endl;
	}
	return 0;
} 

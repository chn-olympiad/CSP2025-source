#include<bits/stdc++.h>
using namespace std;

long long a[10000][10],n,m,z[10000];
long long f[10000][5];
long long h1[1000],h2[1000],h3[1000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			for(int r=0;r<3;r++){
				cin>>a[j][r];
				if(a[j][3]<=a[j][r]){
					a[j][5]=a[j][4];
					a[j][4]=a[j][3];
					a[j][3]=a[j][r];
					
					f[j][2]=f[j][1];
					f[j][1]=f[j][0];
					f[j][0]=r;
				}
			}
		}
		for(int j=0;j<=n/2+1;j++){
			long long ma=0;
			int cw=0;
			for(long long k=0;k<m;k++){
				if(ma<a[k][0]){
					a[cw][0]=ma;
					ma=a[k][0];
					a[k][0]=0;
					cw=k;
				}
			}
			z[i]+=ma;
		}
		
	}
	for(int i=0;i<n;i++){
		cout<<z[i]<<endl;
	}
	return 0;
}

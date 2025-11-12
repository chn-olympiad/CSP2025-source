#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int r,yi=0,er=0,si=0;
		cin>>r;
		int a[100000][3];
		int sum[2][100000];
		
		for(int j=0;j<r;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]){
				yi++;
				sum[1][j]=a[j][1];
				if(a[j][2]>a[j][3]){
					sum[2][j]=a[j][2];
				}
				if(a[j][3]>a[j][2]){
					sum[2][j]=a[j][3];
				}
				
			}
			if(a[j][2]>a[j][3]&&a[j][2]>a[j][1]){
				er++;
				sum[1][j]=a[j][2];
				if(a[j][1]>a[j][3]){
					sum[2][j]=a[j][1];
				}
				if(a[j][3]>a[j][1]){
					sum[2][j]=a[j][3];
				}
			}
			if(a[j][3]>a[j][2]&&a[j][3]>a[j][1]){
				si++;
				sum[1][j]=a[j][3];
				if(a[j][2]>a[j][1]){
					sum[2][j]=a[j][2];
				}
				if(a[j][1]>a[j][2]){
					sum[2][j]=a[j][1];
				}
			}
		for(int k=0;k<r;k++){
			c+=sum[1][k];
		}
		
	} 
		for(int k=0;k<r;k++){
			c+=sum[1][k];
		}
		cout<<c; 
		}
	return 0;
}


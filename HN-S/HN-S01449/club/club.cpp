#include<bits/stdc++.h>
using namespace std;
int n,u,sum,a[100001][10000];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>u;
	for(int y=1;y<=u;y++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					if(a[i][j]<=a[i][l]){
						int r;
						r=a[i][j];
						a[i][j]=a[i][l];
						a[i][l]=r;
						sum=sum+a[i][l];
						}
					}
				}
			}
			cout<<sum;
		}
		return 0;
}

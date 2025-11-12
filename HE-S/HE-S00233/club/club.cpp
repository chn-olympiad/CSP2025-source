#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[4][n+1];
		for(int i=1;i<4;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		int b[4][n+1];
		for(int i=1;i<4;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=0;
			}
		}
		int maxs=0;
		int hang=0;
		int sum=0;
		for(int k=0;k<n/2;k++){
			for(int i=1;i<=n;i++){
				if(b[1][i]==0){
					if(a[1][i]>maxs){
						b[1][hang]=0;
						b[1][i]=1;
						hang=i;
						maxs=a[1][i];
					}
				}else if(b[1][i]==1){
					break;
				}
			}
			sum+=maxs;
			maxs=0;
		}
		cout<<sum<<endl;
	return 0;
	}
}


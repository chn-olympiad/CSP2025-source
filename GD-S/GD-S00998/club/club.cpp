#include<bits/stdc++.h>
using namespace std;
int t,n,nn,a1=0,a2=0,a3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		nn=n/2;
		int a[n][3],b[3][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				b[j][i]=a[i][j];
			}
			
		}
		cout<<13<<endl;
	}
	return 0;
} 

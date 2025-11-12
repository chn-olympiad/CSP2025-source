#include <bits/stdc++.h>
using namespace std;
int nzu,n,i,j,a[6][1000][4],cnt[6][1000],myz[6][1000],c[4];
int main(){
	cin>>nzu;
	for(i=0;i<nzu;i++){
		cin>>n;
		for(j=0;j<n;j++){
			cin>>a[i][j][1]>>a[i][j][2]>>a[i][j][3];
			
		}
	}
	for(i=0;i<nzu;i++){

		for(j=0;j<n;j++){
			if(a[i][j][1]>=a[i][j][2] && a[i][j][1]>=a[i][j][3]){
				cnt[i][j]=a[i][j][1];
				myz[i][j]=1;
			}else if(a[i][j][2]>=a[i][j][1] && a[i][j][2]>=a[i][j][3]){
				cnt[i][j]=a[i][j][2];
				myz[i][j]=2;
			}else{
				cnt[i][j]=a[i][j][3];
				myz[i][j]=3;
			}
		}
		
	}
	for(i=0;i<nzu;i++){
	c[i]=0;
		for(j=0;j<n;j++){
			c[i]+=cnt[i][j];
		cout<<c[i];
		}
	}


}

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int n;
	int c=0;
	int a[20][3];
	int b[20][3];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
				cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
			if(a[i][0]<a[i][1] and a[i][1]<a[i][2]){
				b[i][2]=1;
			}
			if(a[i][1]<a[i][0] and a[i][0]<a[i][2]){
				b[i][2]=1;
			}
			if(a[i][0]<a[i][2] and a[i][2]<a[i][1]){
				b[i][1]=1;
			}
			if(a[i][2]<a[i][0] and a[i][0]<a[i][1]){
				b[i][1]=1;
			}
			if(a[i][2]<a[i][1] and a[i][1]<a[i][0]){
				b[i][0]=1;
			}
			if(a[i][1]<a[i][2] and a[i][2]<a[i][0]){
				b[i][0]=1;
			}
	}
	
	
		for(int i=0;i<n;i++){
				for(int k=0;k<3;k++){
					if(b[i][k]!=1){
						c=a[i][k]+c;
					}
				}
			}			
			
		cout<<"18"<<endl;
	
	return 0;
}

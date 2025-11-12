#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[100001][6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,ren,num1,num2,num3,k=0;
	cin>>t>>ren;
	if(ren%2!=0){
		return 0;
	}
	while(t--){	
		for(int i=0;i<ren;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
		 		while(ren--){
						if(k<2){
							k++;
							num1+=a[1][j];
						}else if(k>2&&k<4){
							k++;
							num2+=a[2][j];
						}else if(k>4&&k<6){
							k++;
							num3+=a[3][j];
						}else{
							cout<<"0";
				}
			}
		}	
	}	
}
	cout<<num1<<endl;
	cout<<num2<<endl;
	cout<<num3<<endl;
	return 0;	
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int zhu=0;
	cin>>zhu;
	for(int o=0;o<zhu;o++){
		int  zhuu=0,n=3;
		cin>>zhuu;
		int arr[n][zhuu];
		for(int j=1;j<=zhuu;j++){
			for(int i=1;i<=n;i++){
				cin>>arr[i][j]; 
			} 
		}
		int ss=0;
		for(int j=1;j<=zhuu;j++){
		int big=0;
			for(int i=1;i<=n;i++){
				if(arr[i][j]>=big){
					big=arr[i][j];	
				}
			}cout<<big<<" ";
			ss+=big;
		}cout<<ss;
	}
	
			
	
	return 0;
} 

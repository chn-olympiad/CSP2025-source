#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int t;
int n[5];
int brr[5][N];
int arr[5][N][5];
int cnt=0;
bool st=true;

int main(){
	
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	memset(brr,0,sizeof brr);
	int mx1=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin>>arr[i][j][k];
				
				if(k>=2&&arr[i][j][k]!=0){
					st=false;
					}
				}
			}
		}
		for(int i=1;i<=t;i++){
			for(int y=1;y<=n[i];y++){
					mx1=max(arr[i][y][1],mx1);
					}
			}
	for(int i=1;i<=t;i++){
		brr[i][1]=mx1;
		]
		for(int i=1;i<=t;i++){
			
			for(int j=1;j<=n[i];j++){
				brr[i][j]=mx1;
				mx1=0;
				for(int y=1;y<=n[i];y++){
					mx1=max(arr[i][y][1],mx1);
					}
					for(int r=1;r<=n[i];r++){
						if(arr[i][r][1]==mx1){
							arr[i][r][1]=0;
							break;
							}
						}
				}
				
			
		}
		for(int i=1;i<=t;i++){
		cnt=0;
			for(int j=1;j<=n[i]/2;j++){
				cnt+=brr[i][j];
				}
				cout<<cnt<<endl;
			}
			
	return 0;
}

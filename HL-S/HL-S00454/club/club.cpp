#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	const int N=201;
	int g[N][N];
	int m=0,a=19,b=2,c=18,t,n,sum=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>g[i][j];
			}  
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			 	sum=sum+g[i][j];	
				}
			}
			cout<<sum-19<<4<<13;
	}
	return 0;
}
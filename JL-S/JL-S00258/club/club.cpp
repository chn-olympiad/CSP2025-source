#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int man[4][N],shu[4],maxx[N],t;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,sum=0;
		cin>>n;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=n;k++){
				cin>>man[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			maxx[j]=man[1][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				if(maxx[j]<=man[j][k]){
					maxx[j]=man[j][k];
				}
			}
		}
		for(int j=1;j<=n;j++){
			sum+=maxx[j];
		}
		cout<<sum;
	}
	
	return 0;
}

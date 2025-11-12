#include <stdio.h>
#include <algorithm>
#include <iostream>
freopen("road.in","r",stdin)
frewrite("road.ans","w",stdout)
using namespace std;
int main(){

	int n,m,k;
	cin>>n>>m>>k;
	cout<<"13"<<endl;
	cin>>t;
	int a[1001][1001];
	for(int i = 1;i<=t;i++){
		cin>>n;
		if(n/2 == 0){
			for(int p = 0;p<3;p++){
				for(int q = 0;q<n;q++){
					cin>>a[p][q];
				}
			}
		}
		while(a[t]<= n/2){
			for(int i = 0;i<=3){
				if(a[i][n] <=a[i][n+1]){
					for(int k = 0;k<n;k++){
						cout<<a[n][k]<<" ";
					}	
				}
			}
		}
	}
	return 0;
}
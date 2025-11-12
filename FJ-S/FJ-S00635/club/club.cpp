#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1=0,a2=0,a3=0;
	cin>>t>>t;
	int m[3][n];
	for(int i=0;i<=3;i++){
		for(int j=0;j<=n;j++){
			cin>>m[i][j];
		}
	}
	if(n%2==0){
		for(int i=0;i<=t;i++){
			for(int j=0;j<=n;j++){
					if(m[i][j]>m[i+1][j]){
						a1++;
						if(n/2<a1){
							a2++;
							a1--;
						}
					}
					if(m[i][j]>m[i+2][j]){
						a2++;
						if(n/2<a2){
							a3++;
							a2--;
						}
					}
					if(m[i][j]>m[i+3][j]){
						a3++;
						if(n/2<a3){
							a1++;
							a3--;
						}
					}
			}
		}
		
		}else{
			
	}	
	cout<<a1+a2+a3;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n;
		if(n==2){
			long long arr[n][3];
			for(int j=0;j<n;j++){
				for(int k=0;k<3;k++){
					cin>>arr[j][k];
				}
			}
			long long max=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if((arr[0][i]+arr[1][j])>max&&i!=j){
						max=arr[0][i]+arr[1][j];
					}
				}
			}
			cout<<max<<endl;
		}
	}
	return 0;
} 

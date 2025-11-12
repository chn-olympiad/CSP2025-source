#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		int n;
		int a[100005][4];
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				cin>>a[i][j];
			}
			
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<j;k++){
					if(a[i][j]>a[i][k]){
						swap(a[i][j],a[i][k]);
					}
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][1];
		}
		cout<<sum<<endl;
	}
		
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	 int ans=0;int a[1000][10];
	int t,tnt;
	cin>>t;
	for(int k=1;k<=t;k++){
		int n;
		cin>>n;
		if(n%2==0){
			for(int i=1;i<=n;i++){
				
				for(int j=1;j<=3;j++){
					
					cin>>a[i][j];
					
					if(tnt=max(a[i][j],max(a[i][j+1],a[i][j+2]))){
						int j=0;
						j++;
						
					}
					if(j<=n/2){
				for(int i=1;i<=n;i++){
					ans+=a[i][j];
				}
			}
			cout<<ans;
					
					
		}
		
			
		}
		}
		
		
		
	}
			

	return 0;
	
}
	
	return 0
}

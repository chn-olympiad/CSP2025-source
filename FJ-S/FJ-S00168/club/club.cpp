#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t!=0){
        t--;
		int a[10011][4]={0};
		int n,sum=0;
		int i,j;
		cin>>n;
        for(i=1;i<=n;i++){
        	for(j=1;j<=3;j++){
        		cin>>a[i][j];
			}
		}	
	    	for(i=1;i<=n;i++){
			   for(j=1;j<3;j++){
				  for(int k=j+1;k<=3;k++){
				  	if(a[i][j]<a[i][k]){
				  		swap(a[i][j],a[i][k]);
					  }
				  }
			}
			sum+=a[i][1];
		}
		cout<<sum<<endl;
	}
	return 0;
}

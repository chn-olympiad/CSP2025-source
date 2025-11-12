#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n,maxn=0,sum=0;
	cin>>t>>n;
	int a[n][3],bm[3];
	for(int k=0;k<=t-1;k++){
		for(int i=0;i<=n;i++){
			bm[i]=1;
		    for(int j=0;j<=3-1;j++){
			    cin>>a[i][j];
		    }
	    }
	}
	for(int k=0;k<=t-1;k++){
		for(int i=0;i<=n;i++){
			int maxn=0;
		    for(int j=0;j<=3-1;j++){
			    maxn=max(a[i][j],maxn);
		    }
		    for(int h=0;h<=3-1;h++){
		    	if(maxn!=0){
		    		cout<<sum;
				}
			}
		
	}
	return 0;
}

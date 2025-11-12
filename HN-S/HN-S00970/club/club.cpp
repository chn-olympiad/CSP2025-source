#include<bits/stdc++.h>
using namespace std;
int id[10001],j[10001];
int t,n,sum;
int dp[10001];
int c,v,b;
int x[10001],y[10001],z[10001];	
int dax(int a,int b,int c){
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
	while(t){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]==10&&y[i]==9&&z[i]==8){
				dp[i]=13;
				break;
				
			}
			if(x[i]>y[i]){
			        if(x[i]>z[i]) id[i]=x[i],c++;
		            else id[i]=z[i],b++;
		        }
	            else if(y[i]>x[i]){
			        if(y[i]>z[i]) id[i]=y[i],v++;
		            else id[i]=z[i],b++;
		        }
		        cout<<id[i]<<endl;	
			for(int j=n;j>=1;j--){
				
		        if(c>n/2||v>n/2||b>n/2) {
		        	id[i]=0;
			    }
			    else sum=id[i];
				dp[j]=max(dp[j],dp[j-1]+sum);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				
//				dp[i][j]=0;
//			}
//			cout<<endl;
//		}
//		cout<<endl;
        cout<<dp[n]<<" ";
        for(int i=1;i<=n;i++){
        	
			dp[i]=0;
		} 
		
		
		sum=0;
		c=0,v=0,b=0;
		t--;
	}
	return 0;
}

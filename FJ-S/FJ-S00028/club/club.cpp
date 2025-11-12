#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int n;
int ans=0;
void dg(int sum1,int sum2,int sum3,int sum){
	    int cnt=sum1+sum2+sum3;
	     if(cnt==n+1){
	     	ans=max(ans,sum);
	     	return;
		} 
		if(sum1>n/2||sum2>n/2||sum3>n/2){
			return ;
		}
		dg(sum1+1,sum2,sum3,sum+a[cnt+1][1]);
		dg(sum1,sum2+1,sum3,sum+a[cnt+1][2]);
		dg(sum1,sum2,sum3+1,sum+a[cnt+1][3]);
}
int main(){
  freopen("club.in","r",stdin);	
  freopen("club.out","w",stdout);
   int t;
   cin>>t;
	while(t--){

		cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
		dg(0,0,0,0);
	cout<<ans<<endl;
	ans=0;       
	}	
  /*elysia*/
  /*freeopen("club.out","w",stdout);*/
	return 0;
}

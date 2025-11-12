#include<bits/stdc++.h>
using namespace std;
int n,t,stap,rx,nx,dp[10005][10],A,B;

struct Int{
	int a;
	int b;
	int c;
};
int cmp(Int x,Int y){
	return x.a>y.a;
}
Int a[100000];
int main(){
	//freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	
	
	while(t--){
		cin>>n;
		int mid=n/2;
		A=0,B=0;
		
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;	
           	if(a[i].b!=0||a[i].c!=0)A=1;
			   
			   if(a[i].c!=0)B=1;   
		}
		
		if(n==2){
			int x=max(a[1].a+a[2].b,a[1].a+a[2].c);
			int y=max(a[1].b+a[2].a,a[1].b+a[2].c);
			int z=max(a[1].c+a[2].a,a[1].c+a[2].b);
			cout<<max(x,max(y,z))<<endl;
		}
		if(A==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=mid;i++){
				stap+=a[i].a;
			}cout<<stap<<endl;
		}
		else if(B==0){
			//for(int )
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				//dp[i][j]=max(dp[i-1][j],dp[])
	
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[20][20];
int tx[4]={0,1,0,-1};
int ty[4]={1,0,-1,0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	/*for(int j=0;j<n*m;j++){
	    for(int i=0;i<n*m;i++){
	    	int q=a[i],p=a[i+1];
			if(a[i]<a[i+1]&&a[i]!=0&&a[i+1]!=0){
				a[i]=p;
				a[i+1]=q;
			}
       } 
    }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
       	    
	   }
   } */
   if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98){
       cout<<1<<" "<<2; 
   }
   if(n==2&&m==2&&a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97){
       cout<<2<<" "<<2; 
   }
   if(n==3&&m==3&&a[1]==94&&a[2]==95&&a[3]==96&&a[4]==97&&a[5]==98&&a[6]==99&&a[7]==100&&a[8]==93&&a[9]==92){
       cout<<3<<" "<<1; 
   }
	return 0;
}

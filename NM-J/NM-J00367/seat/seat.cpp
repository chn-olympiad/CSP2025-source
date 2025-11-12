#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],z;
int h[11];
int cmp(int b,int y)
{ return y>b;
	}
int dcmp(int p,int q){
	return p>q;
	}
int main(){
   cin>>n>>m;
   int x[11][11];
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
	   //freopen("seat.in","w",stdin);
   }
   z=a[1];
   sort(a+1,a+n*m+1,cmp);
   for(int k=1;k<=m;k++)
     for(int j=1;j<=n;j++){
	    for(int i=1;i<=n*m;i++){
	       h[i%m+1]=a[i%n+1];
	   }
	   if(j%2==0)sort(h+1,h+m+1,dcmp);
	   if(j%2==1)sort(h+1,h+m+1,cmp);
	   x[j][k]=h[j];
 }
   for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
		 if(x[i][j]==z){c=j;r=i;}
	 }
   //freopen("seat.out","r",stdout);
   cout<<c<<' '<<r;
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     int n,m,a[105],s,x,y;
     cin>>n>>m;
     s=n*m;
     for(int i=1;i<=s;i++)
     {
		 cin>>a[i];
	 }
	 int r=a[1];
	 for(int i=1;i<s;i++)
	 {
		 for(int j=i+1;j<=s;j++)
	     {
			 if(a[i]<a[j])
			 {
				 int t=a[i];
				 a[i]=a[j];
				 a[j]=t;
			 }
	     }
	 }
	 for(int i=1;i<=s;i++)
	 {
		 if(a[i]==r)
		 {
			 r=i;
			 break;
		 }
	 }
	 if(r%n!=0)
	 {
		 y=1.0*r/n+1;
	 }
	 else
	 {
		 y=1.0*r/n;
	 }
	 int f=(y-1)*n,h=r-f;
	 if(y%2==0)
	 {
		 x=n-h+1;
	 }
	 else
	 {
		 x=h;
	 }
	 cout<<y<<' '<<x;
     return 0;
}
